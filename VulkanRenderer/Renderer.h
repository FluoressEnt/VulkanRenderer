#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>
#include <optional>
#include <iostream>

//#pragma once

class Renderer {
public:
    ~Renderer();

    static Renderer* getGfxDevice();

    void setWindow(GLFWwindow* m_window) { window = m_window; }

    void init();
    
    void renderFrame();

    enum ShaderStage {
        Vertex   = 1 << 0,
        Geometry = 1 << 1,
        Fragment = 1 << 2,
        Compute  = 1 << 3
    };

    void setShaderProgram(std::string shaderName, ShaderStage shaderStage);
    void endShaderProgram();
 
private:
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;  
#endif

    const int MAX_FRAMES_IN_FLIGHT = 2;  
    
    Renderer();

    static Renderer* gfxDevice; //there can only be one!

    GLFWwindow* window;

    std::vector<VkShaderModule> activeShaders;
    std::vector<VkPipelineShaderStageCreateInfo> activeCreateInfo;

    const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
    };  

    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };


    VkInstance instance;   
    VkDebugUtilsMessengerEXT debugMessenger;  
    VkSurfaceKHR surface;  

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    VkQueue graphicsQueue;  
    VkQueue presentQueue;  

    VkSwapchainKHR swapChain;  
    std::vector<VkImage> swapChainImages;  
    VkFormat swapChainImageFormat;  
    VkExtent2D swapChainExtent;  
    std::vector<VkImageView> swapChainImageViews;  
    std::vector<VkFramebuffer> swapChainFramebuffers;  

    VkRenderPass renderPass;  
    VkDescriptorSetLayout descriptorSetLayout;  
    VkPipelineLayout pipelineLayout;  
    VkPipeline graphicsPipeline;  

    VkCommandPool commandPool;  

    VkBuffer vertexBuffer;  
    VkDeviceMemory vertexBufferMemory;  
    VkBuffer indexBuffer;  
    VkDeviceMemory indexBufferMemory;  

    std::vector<VkBuffer> uniformBuffers;  
    std::vector<VkDeviceMemory> uniformBuffersMemory;  

    VkDescriptorPool descriptorPool;  
    std::vector<VkDescriptorSet> descriptorSets;  

    std::vector<VkCommandBuffer> commandBuffers;  

    std::vector<VkSemaphore> imageAvailableSemaphores;  
    std::vector<VkSemaphore> renderFinishedSemaphores;  
    std::vector<VkFence> inFlightFences;  
    std::vector<VkFence> imagesInFlight;  
    size_t currentFrame = 0;  


    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);

    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

    void createGraphicsPipeline();

    VkShaderStageFlagBits getVKShaderFlag(ShaderStage shaderStage);

private:
    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        bool isComplete() {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };

    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    void cleanup();

    void recreateSwapChain();

    void cleanupSwapChain();

    void createInstance();

    void createSurface(GLFWwindow* window);

    void createLogicalDevice();

    void createSwapChain();

    void createImageViews();

    void createRenderPass();

    void createDescriptorSetLayout();

    VkShaderModule createShaderModule(const std::vector<char>& code);


    void createFramebuffers();

    void createCommandPool();

    void createCommandBuffers();

    void createVertexBuffer();

    void createIndexBuffer();

    void createUniformBuffers();

    void updateUniformBuffer(uint32_t currentImage);

    void createDescriptorPool();

    void createDescriptorSets();

    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);

    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    void createSyncObjects();

    void pickPhysicalDevice();

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    bool isDeviceSuitable(VkPhysicalDevice device);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    std::vector<const char*> getRequiredExtensions();

    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    bool checkValidationLayerSupport();

    void setupDebugMessenger();

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
        std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

        return VK_FALSE;
    }

};

