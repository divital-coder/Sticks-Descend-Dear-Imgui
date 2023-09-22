#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <vector>
#include <cstdlib>
#include <ctime>

// Color for glfw main screen background window, the color is set within the glClearColor() and glClear() functions'
ImVec4 windowBackgroundColor = ImVec4(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f);

/*
static void showExampleCustomRendering(){
    ImGui::SetNextWindowSize(ImVec2(800,800));
    ImGui::SetNextWindowPos(ImVec2(1000,100));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.2f, 1.5f, 2.4f, 3.0f));
    if (!ImGui::Begin("Example:Custom rendering", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse)){
        ImGui::End();
        return;
    }

    if (ImGui::BeginTabBar("##TAB BAR")) {
        if (ImGui::BeginTabItem("primitives")) {
            ImGui::PushItemWidth(-ImGui::GetFontSize() * 15);
            ImDrawList* draw_list = ImGui::GetWindowDrawList();


            //drawing gradients rectangulare in shape with colors starting from top left bottom left top right bottom right
            //

            ImGui::Text("Gradients");
            ImVec2 gradient_size = ImVec2(ImGui::CalcItemWidth(), ImGui::GetFrameHeight());
            {
                ImVec2 p0 = ImGui::GetCursorScreenPos();
                ImVec2 p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y);
                ImU32 col_a = ImGui::GetColorU32(IM_COL32(0, 0, 0, 255));
                ImU32 col_b = ImGui::GetColorU32(IM_COL32(255, 255, 255, 255));
                draw_list->AddRectFilledMultiColor(p0,p1,col_a,col_b,col_b,col_a);

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

*/

// section one variables
static bool showSectionOne = true;
static ImVec2 sectionOneDimension = ImVec2(1800.0f, 80.0f);
static ImVec2 sectionOnePosition = ImVec2(50.0f, 10.0f);
static ImVec4 sectionOneBackgroundColor = ImVec4(217.0f / 255.0f, 217.0f / 255.0f, 217.0f / 255.0f, 1.0f);

static void sectionOne(bool p_open)
{
    if (p_open)
    {
        // styling section one
        ImGuiStyle &styleSectionOne = ImGui::GetStyle();
        styleSectionOne.WindowRounding = 19.0f;
        styleSectionOne.FramePadding = ImVec2(20.0f, 5.0f);
        styleSectionOne.FrameRounding = 12.0f;
        styleSectionOne.Colors[ImGuiCol_ButtonHovered] = ImVec4(255.0f, 255.0f, 255.0f, 1.0f);
        styleSectionOne.Colors[ImGuiCol_ButtonActive] = ImVec4(255.0f, 255.0f, 255.0f, 1.0f);
        styleSectionOne.WindowBorderSize = 0.0f;
        // styleSectionOne.Colors[ImGuiCol_Button] = ImVec4(255.0f, 255.0f, 255.0f, 1.0f);
        // styleSectionOne.ScaleAllSizes(1.2f);

        ImGui::SetNextWindowSize(sectionOneDimension);
        ImGui::SetNextWindowPos(sectionOnePosition);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, sectionOneBackgroundColor);
        ImGui::Begin("", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoScrollbar);

        if (ImGui::IsAnyItemHovered())
        {
            ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
        }
        // global for all buttons
        ImGui::SetCursorPosY(25.0f);
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        //^ this is for all buttons

        // Button one
        ImGui::SetCursorPosX(100.0f);
        ImGui::Button("A B O U T");
        ImGui::SameLine();

        // Button two
        ImGui::SetCursorPosX(350.0f);
        ImGui::Button("R A N D O M I Z E");
        ImGui::SameLine();
        // ImGui::Dummy(ImVec2(1.0f, 0.0f));

        // Button three
        ImGui::SetCursorPosX(780.0f);
        ImGui::SetCursorPosY(10.0f);
        ImGui::Button("S O R T I N G \nS E C T I O N");
        ImGui::SameLine();
        // ImGui::Dummy(ImVec2(1.0f, 0.0f));

        // Button four
        ImGui::SetCursorPosX(1100.0f);
        ImGui::Button("T O G G L E  M U S I C");
        ImGui::SameLine();
        // ImGui::Dummy(ImVec2(1.0f, 0.0f));

        // Button five
        ImGui::SetCursorPosX(1400.0f);
        ImGui::Button("T O G G L E  T H E M E");
    }
    ImGui::End();
}

// section Three variables
static bool showSectionThree = true;
static ImVec2 sectionThreeDimension = ImVec2(1800.0f, 800.0f);
static ImVec2 sectionThreePosition = ImVec2(50.0f, 600.0f);
static ImVec4 sectionThreeBackgroundColor = ImVec4(214.0f / 255.0f, 88.0f / 255.0f, 88.0f / 255.0f, 1.0f);

// MAIN SORTING SECTION WITH BARS

static void sectionThree(bool p_open)
{
    ImGuiStyle &styleSectionThree = ImGui::GetStyle();
    if (p_open)
    {
        ImGui::SetNextWindowSize(sectionThreeDimension);
        ImGui::SetNextWindowPos(sectionThreePosition);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, sectionThreeBackgroundColor);
        ImGui::Begin("", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoScrollbar);
    }
    ImGui::End();
}

int main()
{
    if (!glfwInit())
    {
        return 1;
    }

    GLFWwindow *window = glfwCreateWindow(1920, 1080, "Sticks Descend | Dear ImGui", nullptr, nullptr);
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
    static ImFont *sectionsFont = io.Fonts->AddFontFromFileTTF("C:/Users/Pc/Music/Roboto-Bold.ttf", 30.0f);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ImGuiStyle& style = ImGui::GetStyle();

        /*style.WindowRounding = 20.0f;
        style.WindowPadding = ImVec2(20.0f, 20.0f);
        style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
        style.FramePadding = ImVec2(20.0f, 20.0f);
        style.ChildRounding = 20.0f;
        style.FrameRounding = 20.0f;
        style.WindowBorderSize = 10.0f;


        showExampleCustomRendering();
        */

        // sticks descend screen elements
        // section one

        sectionOne(showSectionOne);

        sectionThree(showSectionThree);
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
