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

	// Übung 1

	static CImage getGrayscaleImage(CImage& image);
	static CImage getBinaryImage(CImage& image, int treshold);

	static ImageCoordinate getBrightestPoint(CImage& image);
	static ImageCoordinate getDarkestPoint(CImage& image);

	// Übung 2

	static int getAverageGrayValue(CImage& image);
	static int getIterativeTreshold(CImage& image);

	static CImage getBinaryImage(CImage& image);

	static CImage getLinearHistrogramImage(CImage& image);

	// Übung 3

	static CImage getSmoothenImage(CImage& image);
	static CImage getSharpenImageLaplace(CImage& image, int c);
	static CImage getSharpenImageUnsharpMask(CImage& image, int k);

	// Übung 4

	static CImage gaussianFilter(CImage& image, int radius, bool high);
	static CImage gaussianLowPassFilter(CImage& image, int radius);
	static CImage gaussianHighPassFilter(CImage& image, int radius);

	// Übung 5

	//Vergleichsfunktion fuer qsort
	static void measure(int list[], int length);
	static void serie5Aufg1(CImage& image);

	// Übung 6
	static CImage getLinearHistrogramImageInRGB(CImage& image);

	// Übung 7
	//static CImage sobelfilter2Sides(CImage& image);
	static void sobelfilter2Sides(CImage& image);

	// Übung_08
	static void hairWavelets();

	// Übung_09 habe ich noch nicht gemacht

	//// Übung_10 FloodFilling Algorithmus
	static void floodFill(CImage& image, int label);
	//static CColor floodFillRekursiv(CImage i, int x, int y, int label);

	//Übung_11 
	static CImage moravec(CImage& image);

};
