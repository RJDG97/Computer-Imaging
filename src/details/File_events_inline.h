#pragma once

void MyFrame::OnSave(wxCommandEvent& WXUNUSED(event))
{
    if (!m_imageLoaded)
        return;

    wxString filename = wxSaveFileSelector(_T("Save image as"), _T("*.ppm"));
    if (!filename.empty())
        m_canvas->SaveImage(filename);
}

void MyFrame::OnSaveAs(wxCommandEvent& WXUNUSED(event))
{

}

void MyFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
{
    wxString filename = wxFileSelector(_T("Select file"), _T(""), _T(""), _T(""), _T("All files (*.*)|*.*"));
    if (!filename.empty())
    {
        m_canvas->LoadImage(filename);
        m_imageLoaded = true;
    }
}

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