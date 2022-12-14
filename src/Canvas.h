#pragma once

#include "PPM.h"

class MyCanvas : public wxPanel
{
public:
	MyCanvas(wxWindow* parent, wxWindowID, const wxPoint& pos, const wxSize& size);
	~MyCanvas();
	void LoadImage(wxString fileName);
	void SaveImage(wxString fileName);
	void ProcessImage();
	void BestSize();

	int m_imageWidth;
	int m_imageHeight;
	int m_imageMaxVal;
	wxBitmap m_imageBitmap;	// used to display the image
	wxImage* m_imageRGB;		// used to load the image
	unsigned char* m_myImage;	// used to process the image

	void OnPaint(wxPaintEvent& event);

	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MyCanvas, wxPanel)
EVT_PAINT(MyCanvas::OnPaint)
END_EVENT_TABLE()

MyCanvas::MyCanvas(wxWindow* parent, wxWindowID id,
	const wxPoint& pos, const wxSize& size)
	: wxPanel(parent, id, pos, size, wxSUNKEN_BORDER)
{
	m_myImage = nullptr;
	m_imageRGB = nullptr;
}

MyCanvas::~MyCanvas()
{
	if (m_myImage)
		free(m_myImage);
	if (m_imageRGB)
		delete m_imageRGB;
}

void MyCanvas::LoadImage(wxString fileName)
{
	if (m_myImage)
		free(m_myImage);
	if (m_imageRGB)
		delete m_imageRGB;

	// open image dialog box
	m_imageRGB = new wxImage(fileName, wxBITMAP_TYPE_ANY, -1); // ANY => can load many image formats
	//m_imageBitmap = wxBitmap(*m_imageRGB, -1); // ...to get the corresponding bitmap

	if (m_imageRGB) {

		m_imageWidth = m_imageRGB->GetWidth();
		m_imageHeight = m_imageRGB->GetHeight();
	}
	//m_myImage = (unsigned char*)malloc(m_imageWidth * m_imageHeight * 3);
	//memcpy(m_myImage, m_imageRGB->GetData(), m_imageWidth * m_imageHeight * 3);

	//// update GUI size
	//SetSize(m_imageWidth, m_imageHeight);
	//GetParent()->SetClientSize(GetSize());

	// update display
	Refresh(false);
}

void MyCanvas::SaveImage(wxString fileName)
{
	bool b;

	wxImage* tempImage = new wxImage(m_imageWidth, m_imageHeight, m_myImage, true); // lend my image buffer...
	b = tempImage->SaveFile(fileName);
	delete(tempImage);		// buffer not needed any more

	if (!b)
		wxMessageBox(wxT("A problem occured during saving"));
}

void MyCanvas::ProcessImage()
// example of fast and trivial process (negative)
// you can replace it with your own
// you can also use methods from the wxImage class itself
{
	long int i = m_imageWidth * m_imageHeight * 3;

	// m_myImage is a monodimentional vector of pixels (RGBRGB...)
	while (i--)
		m_myImage[i] = 255 - m_myImage[i];

	Refresh(false); // update display
}

void MyCanvas::BestSize()
{
	SetSize(m_imageWidth, m_imageHeight);	// ideal size for canvas
	GetParent()->SetClientSize(GetSize());	// force the main frame to show the whole canvas
}

void MyCanvas::OnPaint(wxPaintEvent& WXUNUSED(event))
// update the main window content
{
	wxImage* tempImage;  // the bridge between my image buffer and the bitmap to display

	wxPaintDC dc(this);

	if (m_myImage)
	{
		tempImage = new wxImage(m_imageWidth, m_imageHeight, m_myImage, true); // lend my image buffer...
		m_imageBitmap = wxBitmap(*tempImage, -1); // ...to get the corresponding bitmap
		delete(tempImage);		// buffer not needed any more
		dc.DrawBitmap(m_imageBitmap, 0, 0);
	}
}