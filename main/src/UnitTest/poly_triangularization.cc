#include "catch/catch.hpp"

#include <PolygonTriangularization/poly_triang.hh>

#include <fstream>

static void write_obj(const char* _flnm,
  const std::vector<Geo::Vector3>& _plgn,
  const std::vector<std::array<size_t, 3>>& _tris)
{
  std::ofstream ff(std::string(_flnm) + ".obj");
  for (const auto& v : _plgn) { ff << "v" << v << "\n"; }
  for (auto f : _tris)
  {
    for (auto& fi : f)
      fi += 1;
    ff << "f" << f << "\n";
  }
}

#undef TEST_NAME
#define TEST_NAME "poly_1"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn;
  plgn.push_back({ 0, 0, 0 });
  plgn.push_back({ 0, 1, 0 });
  plgn.push_back({ 1, 1, 0 });
  plgn.push_back({ 1, 0, 0 });
  plgn.push_back({ 0.5, 0.5, 0 });
  ptg->add(plgn);
  auto& tris = ptg->triangles();
  REQUIRE(tris.size() == 3);
  REQUIRE(ptg->area() == 0.75);
  write_obj("1", plgn, tris);
}

#undef TEST_NAME
#define TEST_NAME "poly_2"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn;
  plgn.push_back({ 50,   0, 0 });
  plgn.push_back({ 25,  45, 0 });
  plgn.push_back({ -25,  45, 0 });
  plgn.push_back({ 0,  25, 0 });
  plgn.push_back({ -50,   0, 0 });
  plgn.push_back({ -25, -45, 0 });
  plgn.push_back({ 25, -45, 0 });
  plgn.push_back({ 0, -25, 0 });

  ptg->add(plgn);
  auto& tris = ptg->triangles();
  REQUIRE(tris.size() == plgn.size() - 2);
  REQUIRE(ptg->area() == 5125);
  write_obj("2", plgn, tris);
}

#undef TEST_NAME
#define TEST_NAME "poly_3"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn;
  plgn.push_back({ 0,    0,  0 });
  plgn.push_back({ 1,    0,  0 });
  plgn.push_back({ 1,    1, 0 });
  plgn.push_back({ 1.25, 0, 0 });
  plgn.push_back({ 2,    0, 0 });
  plgn.push_back({ 2,    2, 0 });
  plgn.push_back({ 0,    2, 0 });

  ptg->add(plgn);
  auto& tris = ptg->triangles();
  REQUIRE(tris.size() == plgn.size() - 2);
  REQUIRE(ptg->area() == 3.875);
  write_obj("3", plgn, tris);
}

#undef TEST_NAME
#define TEST_NAME "poly_4"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn;
  plgn.push_back({ 0,   1.5, 0 });
  plgn.push_back({ 1,   0,   0 });
  plgn.push_back({ 1,   0.5, 0 });
  plgn.push_back({ 1.5, 0,   0 });
  plgn.push_back({ 2,   0,   0 });
  plgn.push_back({ 2,   2,   0 });
  plgn.push_back({ 0,   2,   0 });

  ptg->add(plgn);
  auto& tris = ptg->triangles();
  REQUIRE(tris.size() == plgn.size() - 2);
  REQUIRE(ptg->area() == 3.125);
  write_obj(TEST_NAME, plgn, tris);
}

#undef TEST_NAME
#define TEST_NAME "poly_5"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn;
  plgn.push_back({ 0,   0,   0 });
  plgn.push_back({ 2,   0,   0 });
  plgn.push_back({ 2,   1,   0 });
  plgn.push_back({ 1,   1,   0 });
  plgn.push_back({ 2,   2,   0 });
  plgn.push_back({ 3,   2,   0 });
  plgn.push_back({ 3,   0,   0 });
  plgn.push_back({ 4,   0,   0 });
  plgn.push_back({ 4,   4,   0 });
  plgn.push_back({ 0,   4,   0 });

  ptg->add(plgn);
  auto& tris = ptg->triangles();
  write_obj(TEST_NAME, plgn, tris);
  REQUIRE(ptg->area() == 13.5);
  REQUIRE(tris.size() == plgn.size() - 2);
}


#undef TEST_NAME
#define TEST_NAME "poly_6"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn;

  plgn.push_back({ 0, 0, 0 });
  plgn.push_back({ 1, 0, 0 });
  plgn.push_back({ 1, 1, 0 });
  plgn.push_back({ 0, 2, 0 });
  plgn.push_back({ -1, 2, 0 });
  plgn.push_back({ -2, 0, 0 });
  plgn.push_back({ -2,-2, 0 });
  plgn.push_back({ 0,-4, 0 });
  plgn.push_back({ 0,-3, 0 });
  plgn.push_back({ -1,-2, 0 });
  plgn.push_back({ -1,-1, 0 });
  plgn.push_back({ -1.5, 0, 0 });
  plgn.push_back({ -1, 0, 0 });
  plgn.push_back({ 0, 1, 0 });

  ptg->add(plgn);
  auto& tris = ptg->triangles();
  write_obj(TEST_NAME, plgn, tris);
  REQUIRE(ptg->area() == 7.25);
  REQUIRE(tris.size() == plgn.size() - 2);
}


#undef TEST_NAME
#define TEST_NAME "poly_7"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();

  std::vector<Geo::Vector3> plgn;
  plgn.push_back({ 0, 0, 0 });
  plgn.push_back({ 3, 0, 0 });
  plgn.push_back({ 3, 3, 0 });
  plgn.push_back({ 0, 3, 0 });
  ptg->add(plgn);

  plgn.clear();
  plgn.push_back({ 1, 1, 0 });
  plgn.push_back({ 2, 1, 0 });
  plgn.push_back({ 2, 2, 0 });
  plgn.push_back({ 1, 2, 0 });
  ptg->add(plgn);

  auto& tris = ptg->triangles();
  write_obj(TEST_NAME, ptg->polygon(), tris);
  REQUIRE(ptg->area() == 8);
  REQUIRE(tris.size() == 8);
}

#undef TEST_NAME
#define TEST_NAME "poly_8"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  {
    std::vector<Geo::Vector3> plgn =
    {
      { 1, 0, 0 },
      { 2, 1, 0 },
      { 1, 2, 0 },
      { 2, 3, 0 },
      { 1, 4, 0 },
      { 2, 5, 0 },
      { 1, 6, 0 },
      {-1, 6, 0 },
      {-2, 5, 0 },
      {-1, 4, 0 },
      {-2, 3, 0 },
      {-1, 2, 0 },
      {-2, 1, 0 },
      {-1, 0, 0 }
    };
    ptg->add(plgn);
  }
  {
    std::vector<Geo::Vector3> plgn =
    {
      { -0.5,  0.5, 0 },
      {  0.5,  0.5, 0 },
      {  0.5,  1.5, 0 },
      { -0.5,  1.5, 0 }
    };
    ptg->add(plgn);
  }
  {
    std::vector<Geo::Vector3> plgn =
    {
      { -0.5,  3.5, 0 },
      {  0.5,  3.5, 0 },
      {  0.5,  4.5, 0 },
      { -0.5,  4.5, 0 }
    };
    ptg->add(plgn);
  }

  auto& tris = ptg->triangles();
  write_obj(TEST_NAME, ptg->polygon(), tris);
  REQUIRE(tris.size() == 24);
  REQUIRE(ptg->area() == 16);
}

#undef TEST_NAME
#define TEST_NAME "poly_9"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  {
    std::vector<Geo::Vector3> plgn =
    {
      { 0, 0, 0 },
      { 1, 0, 0 },
      { 2, 0, 0 },
      { 2, 2, 0 },
      { 0, 2, 0 },
      { 0, 1, 0 },
    };
    ptg->add(plgn);
  }

  auto& tris = ptg->triangles();
  write_obj(TEST_NAME, ptg->polygon(), tris);
  REQUIRE(tris.size() == 4);
  REQUIRE(ptg->area() == 4);
}

#undef TEST_NAME
#define TEST_NAME "poly_10"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn =
  {
    { 38.726774787455334, 0.56712230225691052, -0.144475349131792 },
    { 38.827700000000000, 0.57999999999999996, -0.765400000000000 },
    { 38.631000000000000, 0.58699999999999997, -0.927499999999998 },
    { 38.533099999999997, 0.57110000000000005, -0.161700000000000 },
    { 38.718219076363624, 0.56676148139743932, -0.144170977869948 },
    { 38.726599999999998, 0.56710000000000005, -0.143400000000000 }
  };
  ptg->add(plgn);

  auto& tris = ptg->triangles();
  write_obj(TEST_NAME, ptg->polygon(), tris);
  REQUIRE(tris.size() == 4);
  REQUIRE(ptg->area() > 0.14442415);
  REQUIRE(ptg->area() < 0.144431);
}

#undef TEST_NAME
#define TEST_NAME "poly_11"
TEST_CASE(TEST_NAME, "[PolyTriang]")
{
  auto ptg = IPolygonTriangulation::make();
  std::vector<Geo::Vector3> plgn =
  {
    { 0.057061814887888161, -0.034494051724338268, 0.12295738396624364 },
    { 0.056968958145399401, -0.032443605256421870, 0.11787198073397483 },
    { 0.056963278374730766, -0.032395499739924227, 0.11766664515156007 },
    { 0.056954222265661256, -0.032442336173918618, 0.11750818045197592 },
    { 0.056948522027293433, -0.032342100976387088, 0.11723105716616827 },
    { 0.056653562608728336, -0.029521696175577341, 0.10612705148509588 },
    { 0.057557795199999998, -0.013568500989999999, 0.10652909130000002 }
  };
  ptg->add(plgn);

  auto& tris = ptg->triangles();
  write_obj(TEST_NAME, ptg->polygon(), tris);
}
