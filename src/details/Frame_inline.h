#pragma once
#include "Frame.h"

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1280, 720))
{
    // set the frame icon
    SetIcon(wxICON(sample));
    
    // Splitter
    m_splitter = new wxSplitterWindow(this, -1, wxDefaultPosition, wxSize(1280, 720));
    m_topsplitter = new wxSplitterWindow(m_splitter, -1, wxDefaultPosition, wxSize(1280, 650));
    m_bottomsplitter = new wxSplitterWindow(m_splitter, -1, wxDefaultPosition, wxSize(1280, 70));

    // create the canvas that will manage the image
    m_canvas = new MyCanvas(m_topsplitter, -1, wxDefaultPosition, wxDefaultSize);
    m_imageLoaded = false;

    m_right = new wxPanel(m_topsplitter);

    m_right->SetBackgroundColour(wxColor(200, 100, 100));
    m_bottomsplitter->SetBackgroundColour(wxColor(100, 200, 100));

    m_topsplitter->SplitVertically(m_canvas, m_right);
    m_splitter->SplitHorizontally(m_topsplitter, m_bottomsplitter);
    
    // Menus
#if wxUSE_MENUS
    InitMenus();
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText("Render PPM images using Nearest Neighbour or Bilinear Interpolation");
#endif // wxUSE_STATUSBAR
}

// ----------------------------------------------------------------------------
// Init Functions
// ----------------------------------------------------------------------------
void MyFrame::InitMenus()
{
    // Create Menu Bar
    m_menuBar = new wxMenuBar();
    // Create File Menu
    wxMenu* fileMenu = new wxMenu;
    // Add Menu Items
    fileMenu->Append(Minimal_Save, "Save", "Save");
    fileMenu->Append(Minimal_SaveAs, "Save As", "Save Image");
    fileMenu->Append(Minimal_Open, "Open\tAlt-O", "Open Image");
    fileMenu->Append(Minimal_Quit, "Exit\tAlt-X", "Quit this program");
    // Create Image Renderer Menu
    wxMenu* imagerenderingMenu = new wxMenu;
    wxMenu* interpolationMenu = new wxMenu;
    interpolationMenu->Append(Minimal_NearestNeighbour, "Nearest Neighbour", "Set image interpolation to use nearest neighbour");
    interpolationMenu->Append(Minimal_Bilinear, "Bilinear", "Set image interpolation to use bilinear");
    imagerenderingMenu->AppendSubMenu(interpolationMenu, "Interpolation", " ");
    wxMenu* scalingMenu = new wxMenu;
    scalingMenu->Append(Minimal_Stretch, "Stretch", "Fit image to client size");
    scalingMenu->Append(Minimal_Scaling, "Scaling", "User control in size and position");
    imagerenderingMenu->AppendSubMenu(scalingMenu, "Scaling", " ");
    // Create Edit Menu
    wxMenu* editMenu = new wxMenu;
    editMenu->Append(Minimal_ImageNegative, "Image Negative", "Performs image negative operation");
    editMenu->Append(Minimal_LogTransform, "Log Transform", "Performs log transform operation");
    editMenu->Append(Minimal_GammaTransform, "Gamma Transform", "Performs gamma transform operation");
    editMenu->Append(Minimal_HistogramEqualization, "Histogram Equalization", "Performs histogram equalization");
    // Create Filter Menu
    wxMenu* filterMenu = new wxMenu;
    filterMenu->Append(Minimal_SmoothSetting, "Smooth Settings", "Performs gaussian smoothing filter");
    filterMenu->Append(Minimal_EdgeDetection, "Edge detection", "Performs sobel edge detection");
    filterMenu->Append(Minimal_UnsharpMask, "Unsharp mask", "Performs unsharp mask");
    // Create Analysis Menu
    wxMenu* analysisMenu = new wxMenu;
    analysisMenu->Append(Minimal_ComponentLabeling, "Connected Component Labeling", "Performs Connected Component Labeling Analysis");
    analysisMenu->Append(Minimal_ComponentLabelingDFS, "Connected Component LabelingDFS", "Connected Component Labeling with depth first search");
    // Create Help Menu
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(Minimal_About, "About\tF1", "Show about dialog");

    // Append Menu Items
    m_menuBar->Append(fileMenu, "&File");
    m_menuBar->Append(imagerenderingMenu, "&ImageRendering");
    m_menuBar->Append(editMenu, "&Edit");
    m_menuBar->Append(filterMenu, "&Filter");
    m_menuBar->Append(analysisMenu, "&Analysis");
    m_menuBar->Append(helpMenu, "&Help");

    // Aattach menu bar to the frame
    SetMenuBar(m_menuBar);
}



// ----------------------------------------------------------------------------
// Event Handlers
// ----------------------------------------------------------------------------

#include "File_events_inline.h"
#include "ImageRendering_events_inline.h"
#include "Edit_events_inline.h"
#include "Filter_events_inline.h"
#include "Analysis_events_inline.h"