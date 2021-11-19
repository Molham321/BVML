#include "imageTools.h"

#include <iostream>

using namespace bvme;
using namespace std;


int main()
{
	CImage imageRose("Images/rose_fourier.bmp");



		//Test Übung_01 
	//CImage imageRose("Images/rose_fourier.bmp");
	//imageRose.showImage("orginal");
	//ImageTools::getGrayscaleImage(imageRose).showImage("GrayscaleImage");

	//ImageTools::getBinaryImage(imageRose, 180).showImage("BinaryImage");

	//ImageCoordinate result1 = ImageTools::getBrightestPoint(imageRose);
	//cout << result1.x << "," << result1.y << endl;

	//ImageCoordinate result1 = ImageTools::getDarkestPoint(imageRose);
	//cout << result1.x << "," << result1.y << endl;

		//Test Übung_02
	//CImage imageRose("Images/rose_fourier.bmp");
	//imageRose.showImage("origin");
	//ImageTools::getLinearHistrogramImage(imageRose).showImage("LinearHistrogramImage");

		//Test Übung_05
	//CImage imageSchmetterling_saltpepper("Images/schmetterling_saltpepper.bmp");
	//imageSchmetterling_saltpepper.showImage("orginal");
	//CImage imageSchmetterling_saltpepperGrayImgae = imageSchmetterling_saltpepper.getGreyscaleImage();

	//ImageTools::serie5Aufg1(imageSchmetterling_saltpepperGrayImgae);

	//test Übung_06
	CImage imageRose("Images/rose_rgb_flau.bmp");
	imageRose.showImage("origin");
	ImageTools::getLinearHistrogramImageInRGB(imageRose).showImage("LinearHistrogramImageInRGB");

	system("pause");
	return 0;
}