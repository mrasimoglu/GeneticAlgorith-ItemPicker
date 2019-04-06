#pragma once
#define _HAS_STD_BYTE 0

#include<iostream>
#include<stdint.h>
#include<vector>
#include <random>
#include <algorithm>
#include <assert.h>
#include <Windows.h>


#include "ogl/GL/glew.h"
#include "ogl/GLFW/glfw3.h"

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")


struct Point2D {
	int x, y;

	Point2D() : x(0), y(0) {}
	Point2D(int a, int b) : x(a), y(b) {}
};

struct ColorRGB {
	GLfloat r, g, b;

	ColorRGB(GLfloat x, GLfloat y, GLfloat z) : r(x), g(y), b(z) {}
};


#define numofmeal 10
#define mapsize 7
#define populationsize 75
#define chromosomelength 30
#define mutaterate 0.08
#define selectrate 100
#define crossoverrate 0.9
using Gene = uint8_t;
using Chromosome = std::vector<Gene>;


static std::random_device rnd_device;
static std::mt19937 mersenne_engine{ rnd_device() };
static std::uniform_real_distribution<double> dist{ 0, 1 };