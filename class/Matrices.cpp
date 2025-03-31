#include "Matrices.hpp"

Matrices::Matrices()
{
}

Matrices::~Matrices()
{
}

float *Matrices::getMatrice() {return &this->matrice[0][0];}

void Matrices::setMatrix(float newMatrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrice[i][j] = newMatrix[i][j];
        }
    }
}

void Matrices::loadIdentity()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if (i == j)
                this->matrice[i][j] = 1.0f;
            else
                this->matrice[i][j] = 0.0f;
        }
    }
}


Matrices Matrices::operator*(const Matrices *produit)
{
    Matrices res;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            res.matrice[i][j] = 0;
            for(int k = 0; k < 4; k++)
                res.matrice[i][j] += (this->matrice[i][k] * produit->matrice[k][j]);
        }
    }
    return res;
}

std::array<float, 3> Matrices::applyToVector(const std::array<float, 3> &v) const
{
    std::array<float, 3> result;
    float x = v[0], y = v[1], z = v[2];
    result[0] = matrice[0][0] * x + matrice[0][1] * y + matrice[0][2] * z + matrice[0][3];
    result[1] = matrice[1][0] * x + matrice[1][1] * y + matrice[1][2] * z + matrice[1][3];
    result[2] = matrice[2][0] * x + matrice[2][1] * y + matrice[2][2] * z + matrice[2][3];

    return result;
}

void Matrices::translate(float ax, float ay, float az)
{
    matrice[0][3] = ax;
    matrice[1][3] = ay;
    matrice[2][3] = az;
}


void Matrices::rotate(float angleY, float x, float y, float z)
{
    float rad = angleY * (M_PI / 180.0f);
    float cosA = cos(rad);
    float sinA = sin(rad);
    float oneMinusCosA = 1.0f - cosA;

    float length = sqrt(x * x + y * y + z * z);
    if (length == 0) return;
    x /= length;
    y /= length;
    z /= length;

    float rotation[4][4] = {
        { cosA + x * x * oneMinusCosA, x * y * oneMinusCosA - z * sinA, x * z * oneMinusCosA + y * sinA, 0.0f },
        { y * x * oneMinusCosA + z * sinA, cosA + y * y * oneMinusCosA, y * z * oneMinusCosA - x * sinA, 0.0f },
        { z * x * oneMinusCosA - y * sinA, z * y * oneMinusCosA + x * sinA, cosA + z * z * oneMinusCosA, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    };

    Matrices temp = *this; // Sauvegarde la matrice actuelle
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrice[i][j] = 0.0f;
            for (int k = 0; k < 4; ++k) {
                matrice[i][j] += temp.matrice[i][k] * rotation[k][j];
            }
        }
    }
}

void Matrices::scale(float sx, float sy, float sz)
{
    matrice[0][0] = sx;
    matrice[1][1] = sy;
    matrice[2][2] = sz;
}

void Matrices::perpective(float fov, float aspect, float near, float far)
{
    float tanHalfFov = tanf((fov / 2) * (M_PI / 180.0f));
    float range = near - far;

    matrice[0][0] = 1.0f / (aspect * tanHalfFov);
    matrice[1][1] = 1.0f / tanHalfFov;
    matrice[2][2] = (-near - far) / range;
    matrice[2][3] = 2 * far * near / range;
    matrice[3][2] = -1.0f;
    matrice[3][3] = 0.0f;
}

void Matrices::print() const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrices::lookAt(float eyeX, float eyeY, float eyeZ, 
            float centerX, float centerY, float centerZ, 
            float upX, float upY, float upZ) {

    float fwdX = centerX - eyeX;
    float fwdY = centerY - eyeY;
    float fwdZ = centerZ - eyeZ;

    float fwdLength = std::sqrt(fwdX * fwdX + fwdY * fwdY + fwdZ * fwdZ);
    fwdX /= fwdLength;
    fwdY /= fwdLength;
    fwdZ /= fwdLength;

    float upLength = std::sqrt(upX * upX + upY * upY + upZ * upZ);
    upX /= upLength;
    upY /= upLength;
    upZ /= upLength;

    float rightX = upY * fwdZ - upZ * fwdY;
    float rightY = upZ * fwdX - upX * fwdZ;
    float rightZ = upX * fwdY - upY * fwdX;

    float rightLength = std::sqrt(rightX * rightX + rightY * rightY + rightZ * rightZ);
    rightX /= rightLength;
    rightY /= rightLength;
    rightZ /= rightLength;

    upX = fwdY * rightZ - fwdZ * rightY;
    upY = fwdZ * rightX - fwdX * rightZ;
    upZ = fwdX * rightY - fwdY * rightX;

    matrice[0][0] = rightX;
    matrice[0][1] = rightY;
    matrice[0][2] = rightZ;
    matrice[0][3] = 0.0f;

    matrice[1][0] = upX;
    matrice[1][1] = upY;
    matrice[1][2] = upZ;
    matrice[1][3] = 0.0f;

    matrice[2][0] = -fwdX;
    matrice[2][1] = -fwdY;
    matrice[2][2] = -fwdZ;
    matrice[2][3] = 0.0f;

    matrice[3][0] = - (rightX * eyeX + rightY * eyeY + rightZ * eyeZ);
    matrice[3][1] = - (upX * eyeX + upY * eyeY + upZ * eyeZ);
    matrice[3][2] = fwdX * eyeX + fwdY * eyeY + fwdZ * eyeZ;
    matrice[3][3] = 1.0f;
}

void Matrices::loadToOpenGL()
{
    glLoadMatrixf(&matrice[0][0]);
}