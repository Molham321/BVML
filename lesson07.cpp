#include "imageTools.h"
#include <iostream>

//int filterS1[3][3] = {
//	{ 1, 2, 1 },
//	{ 0, 0, 0 },
//	{-1,-2,-1 }
//};
//
//int filterS2[3][3] = {
//	{ 1, 0,-1 },
//	{ 2, 0,-2 },
//	{ 1, 0,-1 }
//};
//
//CImage getSmoothenImageWithSobel(CImage& original, CImage& clone, int direction) {
//	for (int x = 1; x < original.getHeight() - 1; x++)
//		for (int y = 1; y < original.getWidth() - 1; y++) {
//			int sum = 0;
//
//			for (int s = -1; s <= 1; s++)
//				for (int t = -1; t <= 1; t++) {
//
//
//					int color = original.getPointValue(x + s, y + t).getGrey();
//
//					if (direction == 0) {
//						sum += filterS1[s + 1][t + 1] * color;
//					}
//					else {
//						sum += filterS2[s + 1][t + 1] * color;
//					}
//				}
//
//			CColor color = clone.getPointValue(x, y);
//
//			color.setGrey(sum);
//
//			clone.setPointValue(x, y, color);
//		}
//
//	return clone;
//}
//
//CImage ImageTools::sobelfilter2Sides(CImage& image)
//{
//	CImage greyscaleImage = image.getGreyscaleImage();
//
//	CImage smoothenS1(greyscaleImage.getHeight(), greyscaleImage.getWidth(), true);
//	CImage smoothenS2(greyscaleImage.getHeight(), greyscaleImage.getWidth(), true);
//
//	CImage output(greyscaleImage.getHeight(), greyscaleImage.getWidth(), true);
//
//	getSmoothenImageWithSobel(greyscaleImage, smoothenS1, 0);
//	getSmoothenImageWithSobel(greyscaleImage, smoothenS2, 1);
//
//	for (int x = 0; x < image.getHeight(); x++)
//		for (int y = 0; y < image.getWidth(); y++) {
//			int greyS1 = smoothenS1.getPointValue(x, y).getGrey();
//			int greyS2 = smoothenS2.getPointValue(x, y).getGrey();
//
//			CColor outputColor = output.getPointValue(x, y);
//
//			outputColor.setGrey((greyS1 + greyS2) / 2);
//
//			output.setPointValue(x, y, outputColor);
//		}
//
//	smoothenS1.showImage("Sobelfilter Horizontal");
//	smoothenS2.showImage("Sobelfilter Vertikal");
//
//	return output;
//}

void ImageTools::sobelfilter2Sides(CImage& image)
{
	double s1[3][3] = { {1,2,1},{0,0,0},{-1,-2,-1} };
	double s2[3][3] = { {1,0,-1},{2,0,-2},{1,0,-1} };
	int n = 3;
	int offsetX = 1;
	int offsetY = 1;

	CImage grayImage = image.getGreyscaleImage();

	CImage image_sobel1(grayImage.getHeight(), grayImage.getWidth(), true);
	CImage image_sobel2(grayImage.getHeight(), grayImage.getWidth(), true);

	CImage image_sobel(grayImage.getHeight(), grayImage.getWidth(), true);

	for (int x = offsetX; x < grayImage.getHeight() - offsetX; x++)
	{
		for (int y = offsetY; y < grayImage.getWidth() - offsetY; y++)
		{

			int tmp1 = 0;
			int tmp2 = 0;

			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					int color = grayImage.getPointValue(x + i, y + j).getGrey();

					tmp1 += s1[i + 1][j + 1] * color;
					tmp2 += s2[i + 1][j + 1] * color;
				}
			}

			CColor tmpPoint1 = image_sobel1.getPointValue(x, y);
			CColor tmpPoint2 = image_sobel2.getPointValue(x, y);
			CColor tmpPoint(0);

			tmpPoint1.setGrey(tmp1);
			tmpPoint2.setGrey(tmp2);
			tmpPoint.setGrey((tmp1 + tmp2) / 2);


			image_sobel1.setPointValue(x, y, tmpPoint1);
			image_sobel2.setPointValue(x, y, tmpPoint2);
			image_sobel.setPointValue(x, y, tmpPoint);

			tmp1 = 0;
			tmp2 = 0;
		}
	}

	image_sobel1.showImage("horizontal");
	image_sobel2.showImage("vertikal");
	image_sobel.showImage("mittelwert");
}
