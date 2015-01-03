#include "distance.h"

GeoPoint make_GeoPoint(float x, float y) {
  GeoPoint result;

  result.lat = x;
  result.lng = y;

  return result;
};

GeoPoint to_radians(GeoPoint origin) {
  float x, y;

  x = origin.lat * (M_PI / 180);
  y = origin.lng * (M_PI / 180);

  return make_GeoPoint(x, y);
};

float distance_between(GeoPoint first_point, GeoPoint second_point) {
  GeoPoint p1 = to_radians(first_point);
  GeoPoint p2 = to_radians(second_point);

  float delta_lat = p2.lat - p1.lat;
  float delta_lng = p2.lng - p1.lng;

  float a = 
    pow(sin(delta_lat / 2.0), 2.0) + cos(p1.lat) *
    pow(sin(delta_lng / 2.0), 2.0)* cos(p2.lat);

  float c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

  return c * EARTH_RADIUS;
};
