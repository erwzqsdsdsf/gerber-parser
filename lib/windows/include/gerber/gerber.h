#pragma once

#include <memory>
#include <string>
#include <vector>

#include "gerber_parser/bound_box.h"

class Aperture;
class GerberLevel;

class UnitType {
 public:
  enum Type { guInches, guMillimeters };

  static double Get_mm(double number, Type unit);
};

class GerberApi Gerber {
 public:
  Gerber() {
    unit_ = UnitType::guInches;
    apertures_.resize(3000);  // NOLINT
  }

  bool negative_{false};
  bool IsNegative() const;

  UnitType::Type unit_{UnitType::guMillimeters};
  UnitType::Type Unit() const;

  std::vector<std::shared_ptr<GerberLevel>> levels_;
  std::vector<std::shared_ptr<GerberLevel>> Levels() const;

  BoundBox GetBBox() const;

  std::string name_;
  std::string Name() const;

  std::vector<std::shared_ptr<Aperture>> apertures_;
};
