# ifndef ENUMERATIONS_H
# define ENUMERATIONS_H

#include "MapWinGis.h"

enum ShapeLayerFlags
{	sfVisible = 1,
	slfDrawFill = 2,
	slfDrawLine = 4,
	slfDrawPoint = 8,	
};

enum LayerType
{	ImageLayer,
	ShapefileLayer,
	UndefinedLayer
};
enum LayerFlags
{	Visible = 1
};
    
enum tkFontStyle
{
    fstRegular = 0,
	fstBold = 1,
    fstItalic = 2,
    fstUnderline = 4,
    fstStrikeout = 8,
};

enum tkSimpleShapeType
{
    shpNone = 0,
	shpPoint = 1,
    shpPolyline = 2,
    shpPolygon = 3,
    shpMultiPoint = 4,
};

enum tkExtentsRelation
{
	erNone = 0,
	erEqual = 1,
	erInclude = 2,
	erIsIncluded = 3,
	erIntersection = 4
};

enum tkImageDrawingMethod
{
	idmNewWithResampling = 1,	// new drawing procedures will be used
    idmGDIPlusDrawing = 2,		// GDIPlus rather then GDI darwing will be used
    idmGDIPlusResampling = 4,		// Resampling for GDAL based images will be made by GDI+, otherwise it'll be carried out in tkRaster.cpp (ImageRampling.cpp)
};

struct Point2D 
{
	double x, y;
	Point2D() : x(0.0), y(0.0) {}
	Point2D(double x, double y): x(x), y(y)
	{		
	}

	double GetDistance(Point2D& other) 
	{
		return sqrt(pow(x - other.x, 2.0) + pow(y - other.y, 2.0));
	}
};
enum tkTransformationMode
{
	tmNotDefined = 0,
	tmWgs84Complied = 1,
	tmDoTransformation = 2,
};
enum CacheType 
{ 
	SqliteCache = 0, 
	DiskCache = 1, 
};
# endif