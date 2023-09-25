#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <iostream>

// A BIT OF NOTES FOR IMGUI
// WHILE WORKING WITH WINDOW FUNCTION ALWAYS MAKE SURE TO PROVIDE A UNIQUE STRING TO THESE FUNCTIONS OR OTHERWISE YOUR ELEMENTS WONT RENDER ON THE SCREEN

// global
static bool SECTION_TWO_STATE = false; // GLOBAL VAriable for maintaing section two toggleness

// Color for glfw main screen background window, the color is set within the glClearColor() and glClear() functions

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

// section one FUNCTION

static void sectionOne(bool p_open, ImVec2 sectionOneDimension, ImVec2 sectionOnePosition, ImVec4 sectionOneBackgroundColor)
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

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

        if (ImGui::IsAnyItemHovered())
        {
            ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
        }

        ImGui::Begin("always_put_something_in_your_beginning_text_one", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoScrollbar);

        // global for all buttons

        //^ this is for all buttons

        // Button one
        ImGui::SetCursorPosX(100.0f);
        ImGui::SetCursorPosY(23.0f);
        ImGui::Button("ABOUT");
        ImGui::SameLine();

        // Button two
        ImGui::SetCursorPosX(350.0f);
        ImGui::SetCursorPosY(23.0f);
        ImGui::Button("RANDOMIZE");
        ImGui::SameLine();
        // ImGui::Dummy(ImVec2(1.0f, 0.0f));

        // Button three
        ImGui::SetCursorPosX(780.0f);
        ImGui::SetCursorPosY(5.0f);

        if (ImGui::Button("SORTING \nSECTION"))
        {
            SECTION_TWO_STATE = !SECTION_TWO_STATE;
        };

        ImGui::SameLine();
        // ImGui::Dummy(ImVec2(1.0f, 0.0f));

        // Button four
        ImGui::SetCursorPosX(1100.0f);
        ImGui::SetCursorPosY(23.0f);
        ImGui::Button("TOGGLE MUSIC");
        ImGui::SameLine();
        // ImGui::Dummy(ImVec2(1.0f, 0.0f));

        // Button five
        ImGui::SetCursorPosX(1400.0f);
        ImGui::SetCursorPosY(23.0f);
        ImGui::Button("TOGGLE THEME");

        ImGui::End();
    }
}

// section two function : this include : a dropdown window , a rect with some variable text within it and an icon button along with the label text
static void sectionTwo(bool p_open, ImVec2 sectionTwoDimension, ImVec2 sectionTwoPosition, ImVec4 sectionTwoBackgroundColor, std::vector<std::string> sortingAlgorithmsList, int sortingAlgorithmsIndex, std::string displayedText)
{
    if (p_open)
    {

        ImGuiStyle &styleSectionTwo = ImGui::GetStyle();
        styleSectionTwo.WindowRounding = 10.0f;
        ImGui::SetNextWindowSize(sectionTwoDimension);
        ImGui::SetNextWindowPos(sectionTwoPosition);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, sectionTwoBackgroundColor);
        // section two left section variables
        static ImVec2 sectionTwoLeftWindowDimension = ImVec2(500.0f, 100.0f);
        static ImVec2 sectionTwoLeftWindowPosition = ImVec2(220.0f, 80.0f);
        static ImVec4 sectionTwoLeftWindowBackgroundColor = ImVec4(217.0f / 255.0f, 217.0f / 255.0f, 217.0f / 255.0f, 1.0f);
        static float sectionTwoLeftWindowRounding = 19.0f;
        static std::string sectionTwoLeftWindowSelectedOption = "SORTING ALGOS DROPDOWN";

        // section two middle section variables
        static ImVec2 sectionTwoMiddleWindowDimension = ImVec2(340.0f, 110.0f);
        static ImVec2 sectionTwoMiddleWindowPosition = ImVec2(750.0f, 80.0f);

        static ImVec4 sectionTwoMiddleWindowBackgroundColor = ImVec4(77.0f / 255.0f, 112.0f / 255.0f, 236.0f / 255.0f, 1.0f);
        static float sectionTwoMiddleWindowRounding = 50.0f;

        // sectino two right section

        static ImVec2 sectionTwoRightWindowDimension = ImVec2(100.0f, 100.0f);
        static ImVec2 sectionTwoRightWindowPosition = ImVec2(1100.0f, 85.0f);
        static ImVec4 sectionTwoRightWindowBackgroundColor = ImVec4(217.0f / 255.0f, 217.0f / 255.0f, 217.0f / 255.0f, 1.0f);
        static float sectionTwoRightWindowRounding = 100.0f;

        // sectino two right most section (fourth)
        static ImVec2 sectionTwoRightMostWindowDimension = ImVec2(400.0f, 100.0f);
        static ImVec2 sectionTwoRightMostWindowPosition = ImVec2(1220.0f, 85.0f);
        static ImVec4 sectionTwoRightMostWindowBackgroundColor = ImVec4(217.0f / 255.0f, 217.0f / 255.0f, 217.0f / 255.0f, 1.0f);
        static float sectionTwoRightMostWindowRounding = 19.0f;

        /*-------------------------------------ABOVE THIS ARE THE VARIABLES REQUIRES FOR THE BELOW FUNCTION CALLS FOR IMGUI WINDOWS AND STUFF----------------------------------------------- */

        ImGui::Begin("always_put_something_in_your_beginning_text_two", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);

        // begginning the left side of the middle window

        ImGuiStyle &styleSectionTwoLeftWindow = ImGui::GetStyle();
        styleSectionTwoLeftWindow.WindowRounding = sectionTwoLeftWindowRounding;
        styleSectionTwoLeftWindow.FrameRounding = 12.0f;
        styleSectionTwoLeftWindow.FramePadding = ImVec2(10.0f, 10.0f);
        styleSectionTwoLeftWindow.Colors[ImGuiCol_ButtonHovered] = ImVec4(120.0f / 255.0f, 214.0f / 255.0f, 198.0f / 255.0f, 1.0f);
        // styleSectionTwoLeftWindow.Colors[ImGuiCol_ButtonActive] = ImVec4();

        ImGui::SetNextWindowSize(sectionTwoLeftWindowDimension);
        ImGui::SetNextWindowPos(sectionTwoLeftWindowPosition);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, sectionTwoLeftWindowBackgroundColor);
        ImGui::Begin("section_two_left", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration);

        // stuff inside of imgui sectino two left window

        ImGui::SetCursorPos(ImVec2(65.0f, 30.0f));
        ImGui::SetNextItemWidth(400.0f);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(217.0f / 255.0f, 217.0f / 255.0f, 217.0f / 255.0f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(217.0f / 255.0f, 217.0f / 255.0f, 217.0f / 255.0f, 1.0f));
        if (ImGui::BeginCombo("", sectionTwoLeftWindowSelectedOption.c_str(), ImGuiComboFlags_NoArrowButton))
        {
            // 'selectedOption' is a std::string that holds the currently selected option

            for (int index = 0; index < sortingAlgorithmsList.size(); index++)
            {
                bool isSelected = (sectionTwoLeftWindowSelectedOption == sortingAlgorithmsList[index]); // Check if this option is selected

                // Display the option in the combo box
                if (ImGui::Selectable(sortingAlgorithmsList[index].c_str(), isSelected))
                {
                    sectionTwoLeftWindowSelectedOption = sortingAlgorithmsList[index].c_str(); // Set the selected option if it's clicked
                }

                // You can also use ImGui::SetItemDefaultFocus() to set a default focus option.
                if (isSelected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }

            ImGui::EndCombo();
        }

        ImGui::End();

        // beginning the middle tag imgui sticks descend one
        // rect variables
        ImGui::SetNextWindowSize(sectionTwoMiddleWindowDimension);
        ImGui::SetNextWindowPos(sectionTwoMiddleWindowPosition);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, sectionTwoMiddleWindowBackgroundColor);
        ImGuiStyle &styleSectionTwoMiddleWindow = ImGui::GetStyle();
        styleSectionTwoMiddleWindow.WindowRounding = sectionTwoMiddleWindowRounding;
        styleSectionTwoMiddleWindow.WindowPadding = ImVec2(10.0f, 10.0f);
        ImGui::Begin("section_two_middle", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration);

        ImGui::SetCursorPos(ImVec2(85.0f, 10.0f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(255.0f, 255.0f, 255.0f, 1.0f));
        ImGui::Text("   STICKS-\n  DESCEND\n(DEAR IMGUI)  ");

        ImGui::End();

        // beginning of the right side of the section two
        ImGuiStyle &styleSectionTwoRightWindow = ImGui::GetStyle();
        styleSectionTwoRightWindow.WindowRounding = sectionTwoRightWindowRounding;
        ImGui::SetNextWindowSize(sectionTwoRightWindowDimension);
        ImGui::SetNextWindowPos(sectionTwoRightWindowPosition);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, sectionTwoRightWindowBackgroundColor);
        ImGui::Begin("section_two_right", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration);

        ImGui::SetCursorPos(ImVec2(15.0f, 20.0f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        ImGui::Button("RUN");

        ImGui::End();

        // beginning of the right most window section here
        ImGuiStyle &styleSectionTwoRightMostWindow = ImGui::GetStyle();
        styleSectionTwoRightMostWindow.WindowRounding = sectionTwoRightMostWindowRounding;
        ImGui::SetNextWindowSize(sectionTwoRightMostWindowDimension);
        ImGui::SetNextWindowPos(sectionTwoRightMostWindowPosition);
        ImGui::Begin("section_two_right_most", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);

        ImGui::SetCursorPos(ImVec2(5.0f, 35.0f));
        ImGui::Text("VISUALIZE");
        ImGui::End();
    }
}

// section Three function

// MAIN SORTING SECTION WITH BARS

static void sectionThree(bool p_open, ImVec2 sectionThreeDimension, ImVec2 sectionThreePosition, ImVec4 sectionThreeBackgroundColor)
{

    if (p_open)
    {
        ImGuiStyle &styleSectionThree = ImGui::GetStyle();
        styleSectionThree.WindowRounding = 5.0f;

        ImGui::SetNextWindowSize(sectionThreeDimension);
        ImGui::SetNextWindowPos(sectionThreePosition);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, sectionThreeBackgroundColor);
        ImGui::Begin("always_put_something_in_your_beginning_text_three", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoScrollbar);

        // rectBarsCreation(randomIntegersArray);

        ImGui::End();
    }
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

    // background color main window
    static ImVec4 windowBackgroundColor = ImVec4(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f);

    // section one vars state management with in the main function
    static bool showSectionOne = true;
    static ImVec2 sectionOneDimension = ImVec2(1800.0f, 70.0f);
    static ImVec2 sectionOnePosition = ImVec2(50.0f, 5.0f);
    static ImVec4 sectionOneBackgroundColor = ImVec4(217.0f / 255.0f, 217.0f / 255.0f, 217.0f / 255.0f, 1.0f);

    // setion two vars, state management within the main function
    static bool showSectionTwo = SECTION_TWO_STATE;
    static ImVec2 sectionTwoDimension = ImVec2(1800.0f, 110.0f);
    static ImVec2 sectionTwoPosition = ImVec2(50.0f, 90.0f);
    static ImVec4 sectionTwoBackgroundColor = ImVec4(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f); // section two is already set to no-background using the relevant window flags
    static std::vector<std::string> sortingAlgorithmsList = {"Selection Sort", "Insertion Sort", "Binary Insertion Sort", "Merge Sort", "Quick Sort", "Bubble Sort",
                                                             "Cocktail Shaker Sort", "Gnome Sort", "Comb Sort", "Shell Sort", "Heap Sort", "Smooth Sort", "Odd-Even Sort",
                                                             "Bitonic Sort", "Cycle Sort", "Radix Sort",
                                                             "Tim Sort", "Bogo Sort", "Bozo Sort", "Stooge Sort", "Slow Sort"};
    static int sortingAlgorithmsIndex = 0;
    static std::string displayedText = sortingAlgorithmsList[sortingAlgorithmsIndex];

    // section three vars state management within the main function

    static bool showSectionThree = true;
    static ImVec2 sectionThreeDimension = ImVec2(1800.0f, 800.0f);
    static ImVec2 sectionThreePosition = ImVec2(50.0f, 200.0f);
    static ImVec4 sectionThreeBackgroundColor = ImVec4(214.0f / 255.0f, 88.0f / 255.0f, 88.0f / 255.0f, 1.0f);

    // handing rectangle values creation for random values

    while (!glfwWindowShouldClose(window))
    {
        showSectionTwo = SECTION_TWO_STATE;
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

        sectionOne(showSectionOne, sectionOneDimension, sectionOnePosition, sectionOneBackgroundColor);
        sectionTwo(showSectionTwo, sectionTwoDimension, sectionTwoPosition, sectionTwoBackgroundColor, sortingAlgorithmsList, sortingAlgorithmsIndex, displayedText);
        sectionThree(showSectionThree, sectionThreeDimension, sectionThreePosition, sectionThreeBackgroundColor);

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

// 2 things we learned today, first off all
//dont leave the main functions within the imgui library empty.Its a unique, id for each of the imgui element.
//always provide popStyleColor(), after using the pushStyleColor();
//try defining your global vars for the imgui elements and function within the main function.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// all of your imgui declarative Begin functions within a user defined function go outside of the main function, but the variables based on which they are defined tend to go within the main loop
//
//something to take care of dont forget to include pop style color every time you push a style color of any imgui element
//
//
//
//
