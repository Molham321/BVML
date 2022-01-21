//
//#include <iostream>
//
//CColor ImageTools::floodFillRekursiv(CImage i, int x, int y, int label)
//{
//	CColor BinaryImageColor = i.getPointValue(x, y);
//	return BinaryImageColor = label;
//}
//
////Wert 0 (schwarz)
////Wert 1 (weiß)
////Label 2, 3, . . .
////8-er Nachbarschaft
//
//int g_label = 128;
//
//void ImageTools::floodFill(CImage& image)
//{
//	image.showImage("origin");
//
//	//CImage clone(image.getHeight(), image.getWidth(), false);
//
//	CImage BinaryImage = ImageTools::getBinaryImage(image, 128);
//
//	BinaryImage.showImage("BinaryImageOrigin");
//
//	for (int x = 0; x < image.getHeight(); x++)
//	{
//		for (int y = 0; y < image.getWidth(); y++)
//		{
//			CColor BinaryImageColor = BinaryImage.getPointValue(x, y);
//			CColor binaryColor = 0;
//
//			if (BinaryImageColor.getGrey() == 255)	// binaryColor = 0 || 255
//			{
//				std::cout << "label in " << std::endl;
//
//				 binaryColor = floodFillRekursiv(BinaryImage, x + 1, y, g_label);
//				 binaryColor = floodFillRekursiv(BinaryImage, x, y + 1, g_label);
//				 binaryColor = floodFillRekursiv(BinaryImage, x - 1, y, g_label);
//				 binaryColor = floodFillRekursiv(BinaryImage, x, y - 1, g_label);
//			}
//
//			BinaryImageColor.setRed(binaryColor.getGrey());
//			BinaryImageColor.setGreen(binaryColor.getGrey());
//			BinaryImageColor.setBlue(binaryColor.getGrey());
//
//			BinaryImage.setPointValue(x, y, BinaryImageColor);
//		}
//	}
//
//	BinaryImage.showImage("BinaryImagefloodFill");
//}

//------------------------------------------------------------------------------------------------

/*
	Implementieren Sie den in der Vorlesung besprochenen FloodFilling Algorithmus. Labeln
	Sie die bearbeiteten Pixel beispielsweise mit dem Wert 128.
	Sie können dazu das Bild binaer.bmp verwenden.
*/

/*
	2. Interative Regionenmarkierung (depth-first)
		• Stack verwaltet die noch nicht bearbeiteten Pixel
		• Der sich ergebende Baum wird im depth-first Modus durchlaufen
*/


#include <list>
#include <algorithm>

#include "imageTools.h"

/*
	Wir wollen zunächst nur eine Region markieren
	• Wir suchen zuerst ein unmarkiertes Vordergrundpixel
	• Von diesem ausgehend wird der Rest der Region „gefüllt“
	• Vom Startpixel aus werden alle zusammenhängenden Pixel der
	Region besucht und markiert
*/

void ImageTools::floodFill(CImage& image, int label)
{
	image.showImage("origin");

	std::list<int> my_listX = {};
	std::list<int> my_listY = {};

	//my_listX.push_back(18);

	while (true)
	{

	}
}