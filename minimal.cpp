/////////////////////////////////////////////////////////////////////////////
// Name:        minimal.cpp
// Purpose:     Minimal wxWidgets sample
// Author:      Julian Smart
// Modified by: Renzo Garcia
// Created:     04/01/98
// RCS-ID:      $Id$
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
    #include "wx/splitter.h"
#endif

// ----------------------------------------------------------------------------
// resources
// ----------------------------------------------------------------------------

// the application icon (under Windows and OS/2 it is in resources and even
// though we could still include the XPM here it would be unused)
#ifndef wxHAS_IMAGES_IN_RESOURCES
    #include "../sample.xpm"
#endif

#include "Application.h"

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
IMPLEMENT_APP(MyApp)

// ============================================================================
// implementation
// ============================================================================

// Init
void MyFrame::InitMenus()
{
    // Create Menu Bar
    menuBar = new wxMenuBar();
    // Create File Menu
    wxMenu* fileMenu = new wxMenu;
    // Add Menu Items
    fileMenu->Append(Minimal_Quit, "Save", "Save");
    fileMenu->Append(Minimal_Quit, "Save As", "Save Image");
    fileMenu->Append(Minimal_Quit, "Open\tAlt-O", "Open Image");
    fileMenu->Append(Minimal_Quit, "Exit\tAlt-X", "Quit this program");
    // Create Image Renderer Menu
    wxMenu* imagerenderingMenu = new wxMenu;
    imagerenderingMenu->Append(Minimal_Quit, "Interpolation");
    imagerenderingMenu->Append(Minimal_Quit, "Scaling");
    // Create Edit Menu
    wxMenu* editMenu = new wxMenu;
    editMenu->Append(Minimal_Quit, "Image Negative", "Performs image negative operation");
    editMenu->Append(Minimal_Quit, "Log Transform", "Performs log transform operation");
    editMenu->Append(Minimal_Quit, "Gamma Transform", "Performs gamma transform operation");
    editMenu->Append(Minimal_Quit, "Histogram Equalization", "Performs histogram equalization");
    // Create Filter Menu
    wxMenu* filterMenu = new wxMenu;
    filterMenu->Append(Minimal_Quit, "Smooth Settings", "Performs gaussian smoothing filter");
    filterMenu->Append(Minimal_Quit, "Edge detection", "Performs sobel edge detection");
    filterMenu->Append(Minimal_Quit, "Unsharp mask", "Performs unsharp mask");
    // Create Analysis Menu
    wxMenu* analysisMenu = new wxMenu;
    analysisMenu->Append(Minimal_Quit, "Connected Component Labeling", "Performs Connected Component Labeling Analysis");
    analysisMenu->Append(Minimal_Quit, "Connected Component LabelingDFS", "Connected Component Labeling with depth first search");
    // Create Help Menu
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(Minimal_About, "About\tF1", "Show about dialog");

    // Append Menu Items
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(imagerenderingMenu, "&ImageRendering");
    menuBar->Append(editMenu, "&Edit");
    menuBar->Append(filterMenu, "&Filter");
    menuBar->Append(analysisMenu, "&Analysis");
    menuBar->Append(helpMenu, "&Help");

    // Aattach menu bar to the frame
    SetMenuBar(menuBar);
}

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1280, 720))
{
    // set the frame icon
    SetIcon(wxICON(sample));

    // Panel
    wxPanel* panel = new wxPanel(this, -1);

    // Menus
#if wxUSE_MENUS
    InitMenus();
#endif // wxUSE_MENUS

    // Buttons
    //sizer = new wxBoxSizer(wxVERTICAL);
    //// (size, allignment, shift)
    //sizer->Add(new wxButton(this, -1, "Add"), 0, wxALIGN_RIGHT | wxBOTTOM, 0);
    //sizer->Add(new wxButton(this, -1, "Del"), 0, wxALIGN_RIGHT | wxBOTTOM, 0);
    //SetSizer(sizer);

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText("Render PPM images using Nearest Neighbour or Bilinear Interpolation");
#endif // wxUSE_STATUSBAR
}


// ----------------------------------------------------------------------------
// Event Handlers
// ----------------------------------------------------------------------------

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true is to force the frame to close
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format
                 (
                    "Welcome to %s!\n"
                    "\n"
                    "This is the CS 370 Assignment 1\n"
                    "running under %s.",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                 ),
                 "About wxWidgets minimal sample",
                 wxOK | wxICON_INFORMATION,
                 this);
}
