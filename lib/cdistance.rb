require 'bundler/setup'
require 'ffi'

module Cdistance
  extend FFI::Library

  lib_file = File.expand_path('../ext/cdistance/cdistance', File.dirname(__FILE__))

  if FFI::Platform.mac?
    lib_file << '.bundle'
  end

  ffi_lib FFI.map_library_name(lib_file)

  def self.distance(point1, point2)
    geo_point1 = GeoPoint.new(*point1)
    geo_point2 = GeoPoint.new(*point2)

    distance_between(geo_point1, geo_point2)
  end

  class GeoPoint < FFI::Struct
    layout :lat, :float,
      :lng, :float

    def initialize(lat, lng)
      super()
      self[:lat] = lat
      self[:lng] = lng
    end
  end

  attach_function 'to_radians', [ GeoPoint.by_value ], :float
  attach_function 'distance_between', [ GeoPoint.by_value, GeoPoint.by_value ], :float
end
