#include "imageTools.h"

#include <iostream>

using namespace bvme;
using namespace std;

int main()
{
	CImage imageRoseFourier("Images/rose_fourier.bmp");
	CImage imageRose("Images/rose.bmp");
	CImage imageRoseFlau("Images/rose_flau.bmp");
	CImage imageRoseRgbFlau("Images/rose_rgb_flau.bmp");
	CImage imageSchmetterlingSaltpepper("Images/schmetterling_saltpepper.bmp");
	CImage imageText1("Images/text1.bmp");
	CImage imageSchachbrett("Images/schachbrett.bmp");
	CImage imageMond("Images/mond.bmp");
	CImage imageReis("Images/reis.bmp");

	CImage imageLinienkreis("Images/linienkreis.bmp");
	CImage imageCalvin("Images/calvin.bmp");

	//Test Übung_01 
	//imageRose.showImage("origin");
	//ImageTools::getGrayscaleImage(imageRose).showImage("GrayscaleImage");
	//ImageTools::getBinaryImage(imageText1, 65).showImage("BinaryImage");

	//ImageCoordinate result1 = ImageTools::getBrightestPoint(imageRose);
	//cout << result1.x << "," << result1.y << endl;

	//ImageCoordinate result1 = ImageTools::getDarkestPoint(imageRose);
	//cout << result1.x << "," << result1.y << endl;

	//Test Übung_02
	//int result1 = ImageTools::getAverageGrayValue(imageRoseFourier);
	//cout << result1 << endl;

	//int result2 = ImageTools::getIterativeTreshold(imageRoseFourier);
	//cout << result2 << endl;

	//ImageTools::getBinaryImage(imageText1).showImage("BinaryImage");
	//ImageTools::getLinearHistrogramImage(imageRoseFourier).showImage("LinearHistrogramImage");

	//Test Übung_03
	imageSchachbrett.showImage("origin");
	ImageTools::getSmoothenImage(imageSchachbrett).showImage();

	//Test Übung_04
	//imageSchachbrett.showImage();
	//ImageTools::gaussianLowPassFilter(imageSchachbrett, 0).showImage();

	//Test Übung_05
	//CImage imageSchmetterling_saltpepper("Images/schmetterling_saltpepper.bmp");
	//imageSchmetterling_saltpepper.showImage("orginal");
	//CImage imageSchmetterling_saltpepperGrayImgae = imageSchmetterling_saltpepper.getGreyscaleImage();
	//ImageTools::serie5Aufg1(imageSchmetterling_saltpepperGrayImgae);

	//test Übung_06
	//ImageTools::getLinearHistrogramImageInRGB(imageRoseRgbFlau).showImage("LinearHistrogramImageInRGB");

	// Test Übung_07
	//ImageTools::SobelFilter(imageRose).showImage("SobelFilter");
	//ImageTools::sobelfilter2Sides(imageRose);

	// Test Übung_08
	//ImageTools::hairWavelets();

	//// Test Übung_10
	//ImageTools::floodFill(imageSchachbrett);

	//Test Übung_11
	//CImage pic = ImageTools::moravec(imageSchachbrett);
	//imageSchachbrett.showImage();
	//pic.showImage();

	// Test Übung_12

	//CImage imageLinien("Images/linien.bmp");

	//imageLinien.showImage("origin");
	//imageLinien = ImageTools::houghTransformation(imageLinien);
	//imageLinien.showImage("houghTransformation");

	system("pause");
	return 0;
}