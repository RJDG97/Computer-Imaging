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

void SkipComments(wxTextFile& file, wxString& line)
{
    line = line.BeforeFirst('#');
    if (line.empty())
        line = file.GetNextLine();
}

void MyFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
{
    wxString filename = wxFileSelector(_T("Select file"), _T(""), _T(""), _T(""), _T("All files (*.*)|*.*"));
    if (!filename.empty())
    {
        wxTextFile file;
        file.Open(filename);
        if (file.GetFirstLine() == "P3")
        {
            wxString line = file.GetNextLine();
            SkipComments(file, line);
            // Get image size
            m_canvas->m_imageWidth = wxAtoi(line);
            line = line.AfterFirst(' ');
            m_canvas->m_imageHeight = wxAtoi(line);
            // Allocate Size
            m_canvas->m_myImage = (unsigned char*)malloc(m_canvas->m_imageWidth * m_canvas->m_imageHeight);
            // Get image max color
            line = file.GetNextLine();
            SkipComments(file, line);
            m_canvas->m_imageMaxVal = wxAtoi(line);
            // Store Values
            for (auto c : line)
            {
                
            }
            line = file.GetNextLine();
            SkipComments(file, line);

            SetStatusText(wxString::Format(wxT("%i"), m_canvas->m_imageHeight));
        }
        else if (file.GetFirstLine() == "P6")
        {
        }
        else
        {
            SetStatusText("Invalid File Format");
        }

        // m_canvas->LoadImage(filename);
        // m_imageLoaded = true;

        file.Close();
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