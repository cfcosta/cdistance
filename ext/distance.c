#include "distance.h"

geo_point make_geo_point(float x, float y) {
  geo_point result;

  result.lat = x;
  result.lng = y;

  return result;
};

geo_point to_radians(geo_point origin) {
  float x, y;

  x = origin.lat * (M_PI / 180);
  y = origin.lng * (M_PI / 180);

  return make_geo_point(x, y);
};

float distance_between(geo_point first_point, geo_point second_point) {
  geo_point p1 = to_radians(first_point);
  geo_point p2 = to_radians(second_point);

  float delta_lat = p2.lat - p1.lat;
  float delta_lng = p2.lng - p1.lng;

  float a = 
    pow(sin(delta_lat / 2.0), 2.0) + cos(p1.lat) *
    pow(sin(delta_lng / 2.0), 2.0)* cos(p2.lat);

  float c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

  return c * EARTH_RADIUS;
};
