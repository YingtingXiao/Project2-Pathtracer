// CIS565 CUDA Raytracer: A parallel raytracer for Patrick Cozzi's CIS565: GPU Computing at the University of Pennsylvania
// Written by Yining Karl Li, Copyright (c) 2012 University of Pennsylvania
// This file includes code from:
//       Rob Farber for CUDA-GL interop, from CUDA Supercomputing For The Masses: http://www.drdobbs.com/architecture-and-design/cuda-supercomputing-for-the-masses-part/222600097
//       Peter Kutz and Yining Karl Li's GPU Pathtracer: http://gpupathtracer.blogspot.com/
//       Yining Karl Li's TAKUA Render, a massively parallel pathtracing renderer: http://www.yiningkarlli.com

#ifndef RAYTRACEKERNEL_H
#define PATHTRACEKERNEL_H

#include <stdio.h>
#include <thrust/random.h>
#include <cuda.h>
#include <cmath>
#include "sceneStructs.h"

#if CUDA_VERSION >= 5000
    #include <helper_math.h>
#else
    #include <cutil_math.h>
#endif

void cudaRaytraceCore(uchar4* PBOpos, camera* renderCam, cameraData cam, int iterations,
											staticGeom* cudageoms, int numberOfGeoms, glm::vec3* cudavertices,
											glm::vec3* normals, triangle* cudafaces, int numberOfFaces,
											material* cudamtls, glm::vec3* cudaimage, ray* raypool1,
											ray* raypool2, int numberOfRays, int* scanArray, int* sumArray1,
											int* sumArray2);
void checkCUDAError(const char *msg);

#endif
