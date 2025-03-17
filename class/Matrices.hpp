#pragma once
#include "../include/scop.hpp"

class Matrices
{
    private:
        float matrice[4][4];
    public:
        Matrices();
        ~Matrices();

        void loadIdentity();
        Matrices operator*(const Matrices *produit);
        std::array<float, 3> applyToVector(const std::array<float, 3> &v) const;

        float *getMatrice(void);
        void setMatrix(float newMatrix[4][4]);

        void translate(float ax, float ay, float az);
        void rotate(float angleY, float x, float y, float z);
        void scale(float sx, float sy, float sz);
        void perpective(float fov, float aspect, float near, float far);
        void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);

        void loadToOpenGL();
        void print() const;
};

