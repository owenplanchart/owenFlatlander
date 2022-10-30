#pragma once

#include "ofMain.h"
#include "FunkyTriangle.h"
//  FunkyTriangleSystem.hpp
//  owenFlatlander
//
//  Created by Eugenio Planchart Carnevali on 29/10/2022.
//
class FunkyTriangleSystem{
    
    public:
        FunkyTriangleSystem();
        void setup(int _numOfTriangles);
        void update();
        void draw();
    
    private:
        vector <FunkyTriangle> FunkyTriangles;\
        int numOfTriangles;
};
