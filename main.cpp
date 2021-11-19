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
	CImage imageLinien("Images/linien.bmp");
	CImage imageLinienkreis("Images/linienkreis.bmp");
	CImage imageCalvin("Images/calvin.bmp");

	//imageRoseFourier.showImage("orginal");
	//imageRose.showImage("orginal");
	//imageRoseFlau.showImage("orginal");
	//imageRoseRgbFlau.showImage("orginal");
	//imageSchmetterlingSaltpepper.showImage("orginal");
	//imageText1.showImage("orginal");
	//imageSchachbrett.showImage("orginal");
	//imageMond.showImage("orginal");
	//imageReis.showImage("orginal");
	//imageLinien.showImage("orginal");
	//imageLinienkreis.showImage("orginal");
	//imageCalvin.showImage("orginal");


	//Test Übung_01 
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


	//Test Übung_05
	//CImage imageSchmetterling_saltpepper("Images/schmetterling_saltpepper.bmp");
	//imageSchmetterling_saltpepper.showImage("orginal");
	//CImage imageSchmetterling_saltpepperGrayImgae = imageSchmetterling_saltpepper.getGreyscaleImage();

	//ImageTools::serie5Aufg1(imageSchmetterling_saltpepperGrayImgae);

	//test Übung_06
	ImageTools::getLinearHistrogramImageInRGB(imageRoseRgbFlau).showImage("LinearHistrogramImageInRGB");

	system("pause");
	return 0;
}