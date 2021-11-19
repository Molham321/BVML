#pragma once
#include "CImage.h"

using namespace bvme;

struct ImageCoordinate {
	int x;
	int y;
};

class ImageTools
{
public:

	// �bung 1

	static CImage getGrayscaleImage(CImage& image);
	static CImage getBinaryImage(CImage& image, int treshold);

	static ImageCoordinate getBrightestPoint(CImage& image);
	static ImageCoordinate getDarkestPoint(CImage& image);

	static CImage highlightPoint(CImage& image, ImageCoordinate coordinates, int radius);

	// �bung 2

	static int getAverageGrayValue(CImage& image);
	static int getIterativeTreshold(CImage& image);

	static CImage getBinaryImage(CImage& image);

	static CImage getLinearHistrogramImage(CImage& image);

	// �bung 3

	static CImage getSmoothenImage(CImage& image);
	static CImage getSharpenImageLaplace(CImage& image, int c);
	static CImage getSharpenImageUnsharpMask(CImage& image, int k);

	// �bung 4

	static CImage gaussianFilter(CImage& image, int radius, bool high);
	static CImage gaussianLowPassFilter(CImage& image, int radius);
	static CImage gaussianHighPassFilter(CImage& image, int radius);

	// �bung 5

	//Vergleichsfunktion fuer qsort
	static void measure(int list[], int length);
	static void serie5Aufg1(CImage& image);

	// �bung 6
	static CImage getLinearHistrogramImageInRGB(CImage& image);
};
