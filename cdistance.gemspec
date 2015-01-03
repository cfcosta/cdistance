# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'cdistance/version'

Gem::Specification.new do |spec|
  spec.name          = "cdistance"
  spec.version       = Cdistance::VERSION
  spec.authors       = ["Cainã Costa"]
  spec.email         = ["cainan.costa@gmail.com"]
  spec.summary       = %q{Distance between two geographic points in pure C.}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.require_paths = ["lib"]
  spec.extensions    = ["ext/cdistance/extconf.rb"]

  spec.add_development_dependency "bundler", "~> 1.7"
  spec.add_development_dependency "rake", "~> 10.0"
end
