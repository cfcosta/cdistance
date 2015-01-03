#ifndef _H_DISTANCE
#define _H_DISTANCE

#include <math.h>
#include <stdio.h>

#define EARTH_RADIUS 6371.0

typedef struct {
  float lat;
  float lng;
} geo_point;

geo_point make_geo_point(float, float);
geo_point to_radians(geo_point);
float distance_between(geo_point, geo_point);
#endif
