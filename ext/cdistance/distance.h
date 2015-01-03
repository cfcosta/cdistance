#ifndef _H_DISTANCE
#define _H_DISTANCE

#include <math.h>
#include <stdio.h>

#define EARTH_RADIUS 6371.0

typedef struct {
  float lat;
  float lng;
} GeoPoint;

GeoPoint make_GeoPoint(float, float);
GeoPoint to_radians(GeoPoint);
float distance_between(GeoPoint, GeoPoint);
#endif
