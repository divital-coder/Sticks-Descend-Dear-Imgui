#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <vector>
#include <cstdlib>
#include <ctime>

// Color for glfw main screen background window, the color is set within the glClearColor() and glClear() functions'
ImVec4 windowBackgroundColor = ImVec4(5.0f, 0.4f, 0.3f, 1.0f);

static void showExampleCustomRendering()
{
    ImGui::SetNextWindowSize(ImVec2(800, 800));
    ImGui::SetNextWindowPos(ImVec2(1000, 100));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.2f, 1.5f, 2.4f, 3.0f));
    if (!ImGui::Begin("Example:Custom rendering", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::End();
        return;
    }

    if (ImGui::BeginTabBar("##TAB BAR"))
    {
        if (ImGui::BeginTabItem("primitives"))
        {
            ImGui::PushItemWidth(-ImGui::GetFontSize() * 15);
            ImDrawList *draw_list = ImGui::GetWindowDrawList();

            // drawing gradients rectangulare in shape with colors starting from top left bottom left top right bottom right
            //

            ImGui::Text("Gradients");
            ImVec2 gradient_size = ImVec2(ImGui::CalcItemWidth(), ImGui::GetFrameHeight());
            {
                ImVec2 p0 = ImGui::GetCursorScreenPos();
                ImVec2 p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y);
                ImU32 col_a = ImGui::GetColorU32(IM_COL32(0, 0, 0, 255));
                ImU32 col_b = ImGui::GetColorU32(IM_COL32(255, 255, 255, 255));
                draw_list->AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a);
            }
            {
                ImVec2 p0 = ImGui::GetCursorScreenPos();
                ImVec2 p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y);
                ImU32 col_a = ImGui::GetColorU32(IM_COL32(0, 0, 0, 255));
                ImU32 col_b = ImGui::GetColorU32(IM_COL32(255, 255, 255, 255));
                draw_list->AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a);
            }
            {
                ImVec2 p0 = ImGui::GetCursorScreenPos();
                ImVec2 p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y);
                ImU32 col_a = ImGui::GetColorU32(IM_COL32(0, 255, 0, 255));
                ImU32 col_b = ImGui::GetColorU32(IM_COL32(255, 0, 0, 255));
                draw_list->AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a);
            }

            ImGui::PopItemWidth();
            ImGui::EndTabItem();
        }
    }
}

int main()
{
    if (!glfwInit())
    {
        return 1;
    }

    GLFWwindow *window = glfwCreateWindow(1920, 1080, "Fullscreen window", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return 1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGuiStyle &style = ImGui::GetStyle();
        style.WindowRounding = 20.0f;
        style.WindowPadding = ImVec2(20.0f, 20.0f);
        style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
        style.FramePadding = ImVec2(20.0f, 20.0f);
        style.ChildRounding = 20.0f;
        style.FrameRounding = 20.0f;
        style.WindowBorderSize = 10.0f;

        showExampleCustomRendering();

        // iMGUI: COMPONENTES RENDERING
        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(windowBackgroundColor.w, windowBackgroundColor.x, windowBackgroundColor.y, windowBackgroundColor.z);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
    // cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;

    // hola como tale tale vu
}
