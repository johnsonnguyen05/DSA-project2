#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <cmath>

// change if you choose to use a different header name
#include "AdjacencyList.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be
// unique, but you can group multiple tests with [tags]. A test can have
// [multiple][tags] using that syntax.
TEST_CASE("PageRank calculation normal", "[pageRank]") {
  AdjacencyList graph;
  graph.insert("google.com", "gmail.com");
  graph.insert("google.com", "maps.com");
  graph.insert("facebook.com", "ufl.edu");
  graph.insert("ufl.edu", "google.com");
  graph.insert("ufl.edu", "gmail.com");
  graph.insert("maps.com", "facebook.com");
  graph.insert("gmail.com", "maps.com");

  graph.pageRank(2);

  map<string, pair<vector<pair<string, float>>, float>> output = graph.getGraph();
  REQUIRE(output["facebook.com"].second == 0.20f);
  REQUIRE(output["gmail.com"].second == 0.20f);
  REQUIRE(output["google.com"].second == 0.10f);
  REQUIRE(output["maps.com"].second == 0.30f);
  REQUIRE(output["ufl.edu"].second == 0.20f);
}

TEST_CASE("PageRank calculation power_iterations", "[pageRank]") {
  AdjacencyList graph;
  graph.insert("google.com", "gmail.com");
  graph.insert("google.com", "maps.com");
  graph.insert("facebook.com", "ufl.edu");
  graph.insert("ufl.edu", "google.com");
  graph.insert("ufl.edu", "gmail.com");
  graph.insert("maps.com", "facebook.com");
  graph.insert("gmail.com", "maps.com");

  graph.pageRank(1000);

  map<string, pair<vector<pair<string, float>>, float>> output = graph.getGraph();
  REQUIRE((ceil(output["facebook.com"].second * 100) / 100) == 0.24f);
  REQUIRE((ceil(output["gmail.com"].second * 100) / 100) == 0.18f);
  REQUIRE((ceil(output["google.com"].second * 100) / 100) == 0.12f);
  REQUIRE((ceil(output["maps.com"].second * 100) / 100) == 0.24f);
  REQUIRE((ceil(output["ufl.edu"].second * 100) / 100)== 0.24f);
}

TEST_CASE("PageRank calculation 2", "[pageRank]") {
  AdjacencyList graph;
  graph.insert("zoom.us", "facebook.com");
  graph.insert("python.org", "zoom.us");
  graph.insert("facebook.com", "python.org");
  graph.insert("facebook.com", "google.com");
  graph.insert("google.com", "aman.com");
  graph.insert("aman.com", "zoom.us");
  graph.insert("python.org", "aman.com");
  graph.insert("aman.com", "python.org");

  graph.pageRank(14);

  map<string, pair<vector<pair<string, float>>, float>> output = graph.getGraph();
  REQUIRE((ceil(output["aman.com"].second * 100) / 100) == 0.29f);
  REQUIRE((ceil(output["facebook.com"].second * 100) / 100) == 0.14f);
  REQUIRE((ceil(output["google.com"].second * 100) / 100) == 0.08f);
  REQUIRE((ceil(output["python.org"].second * 100) / 100) == 0.24f);
  REQUIRE((ceil(output["zoom.us"].second * 100) / 100)== 0.26f);
}


TEST_CASE("Adding vertices and edges", "[insertion]") {
  AdjacencyList graph;
  graph.insert("google.com", "gmail.com");
  graph.insert("google.com", "maps.com");
  graph.insert("facebook.com", "ufl.edu");
  graph.insert("ufl.edu", "google.com");
  graph.insert("ufl.edu", "gmail.com");
  graph.insert("maps.com", "facebook.com");
  graph.insert("gmail.com", "maps.com");

  map<string, pair<vector<pair<string, float>>, float>> output = graph.getGraph();
  REQUIRE(output["google.com"].first[0].first == "gmail.com");
  REQUIRE(output["google.com"].first[1].first == "maps.com");
  REQUIRE(output["gmail.com"].first[0].first == "maps.com");
  REQUIRE(output["maps.com"].first[0].first == "facebook.com");
  REQUIRE(output["facebook.com"].first[0].first == "ufl.edu");
  REQUIRE(output["ufl.edu"].first[0].first == "google.com");
  REQUIRE(output["ufl.edu"].first[1].first == "gmail.com");
}
