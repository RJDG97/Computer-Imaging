#pragma once

// Define a new frame type: this is going to be our main frame
class MyFrame : public wxFrame
{
public:
    // ctor(s)
    MyFrame(const wxString& title);

    // Initializer
    void InitMenus();

    // event handlers (these functions should _not_ be virtual)
    //File
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    // Image Rendering
    void OnNearestNeighbour(wxCommandEvent& event);
    void OnBilinear(wxCommandEvent& event);
    void OnStretch(wxCommandEvent& event);
    void OnScaling(wxCommandEvent& event);
    // Edit
    void OnImageNegative(wxCommandEvent& event);
    void OnLogTransform(wxCommandEvent& event);
    void OnGammaTransform(wxCommandEvent& event);
    void OnHistogramEqualization(wxCommandEvent& event);
    // Filter
    void OnSmoothingSettings(wxCommandEvent& event);
    void OnEdgeDetection(wxCommandEvent& event);
    void OnUnsharpMask(wxCommandEvent& event);
    // Analysis
    void OnComponentLabeling(wxCommandEvent& event);
    void OnComponentLabelingDFS(wxCommandEvent& event);
    // Help
    void OnAbout(wxCommandEvent& event);

private:
    // any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();

    wxMenuBar* m_menuBar;

    wxSplitterWindow* m_splitter;
    wxSplitterWindow* m_topsplitter;
    wxSplitterWindow* m_bottomsplitter;
    wxPanel* m_right;

    wxBoxSizer* m_sizer;

    MyCanvas* m_canvas; // the canvas inside the main frame
    bool m_imageLoaded;
};

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum
{
    // menu items
    Minimal_Save = wxID_SAVE,
    Minimal_SaveAs = wxID_SAVEAS,
    Minimal_Open = wxID_OPEN,
    Minimal_Quit = wxID_EXIT,
    
    Minimal_NearestNeighbour, // = wxID_INTERPOLATION,
    Minimal_Bilinear, // = wxID_INTERPOLATION,
    Minimal_Stretch, // = wxID_INTERPOLATION,
    Minimal_Scaling,// = wxID_SCALING,

    Minimal_ImageNegative,// = wxID_IMAGENEGATIVE,
    Minimal_LogTransform,// = wxID_LOGTRANSFORM,
    Minimal_GammaTransform,// = wxID_GAMMATRANSFORM,
    Minimal_HistogramEqualization,// = wxID_HISTOGRAMEQUALIZATION,

    Minimal_SmoothSetting,// = wxID_SMOOTHSETTING,
    Minimal_EdgeDetection,// = wxID_EDGEDETECTION,
    Minimal_UnsharpMask,// = wxID_UNSHARPMASK,

    Minimal_ComponentLabeling,// = wxID_COMPONENTLABELING,
    Minimal_ComponentLabelingDFS,// = wxID_COMPONENTLABELINGDFS,

    // it is important for the id corresponding to the "About" command to have
    // this standard value as otherwise it won't be handled properly under Mac
    // (where it is special and put into the "Apple" menu)
    Minimal_About = wxID_ABOUT
};

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------

// the event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
// File
EVT_MENU(Minimal_Save, MyFrame::OnSave)
EVT_MENU(Minimal_SaveAs, MyFrame::OnSaveAs)
EVT_MENU(Minimal_Open, MyFrame::OnOpen)
EVT_MENU(Minimal_Quit, MyFrame::OnQuit)
// Image Renderer
EVT_MENU(Minimal_NearestNeighbour, MyFrame::OnNearestNeighbour)
EVT_MENU(Minimal_Bilinear, MyFrame::OnBilinear)
EVT_MENU(Minimal_Stretch, MyFrame::OnStretch)
EVT_MENU(Minimal_Scaling, MyFrame::OnScaling)
// Edit
EVT_MENU(Minimal_ImageNegative, MyFrame::OnImageNegative)
EVT_MENU(Minimal_LogTransform, MyFrame::OnLogTransform)
EVT_MENU(Minimal_GammaTransform, MyFrame::OnGammaTransform)
EVT_MENU(Minimal_HistogramEqualization, MyFrame::OnHistogramEqualization)
// Filter
EVT_MENU(Minimal_SmoothSetting, MyFrame::OnSmoothingSettings)
EVT_MENU(Minimal_EdgeDetection, MyFrame::OnEdgeDetection)
EVT_MENU(Minimal_UnsharpMask, MyFrame::OnUnsharpMask)
// Analysis
EVT_MENU(Minimal_ComponentLabeling, MyFrame::OnComponentLabeling)
EVT_MENU(Minimal_ComponentLabelingDFS, MyFrame::OnComponentLabelingDFS)
// Help
EVT_MENU(Minimal_About, MyFrame::OnAbout)
wxEND_EVENT_TABLE()