#include "prism.h"
Prism::Prism()
{

}
Prism::Prism(int n, float r, float h, float ex, float ey, float ez, float d)
{
    p_n = n;
    p_r = r;
    p_h = h;
    p_ex = -ex;
    p_ey = -ey;
    p_ez = -ez;
    p_d = d;
    init_points();
}
void Prism::init_points()
{
    float phi = 360.0 / p_n;
    for (int i = 0; i < p_n; i++)
    {
        points.append(glm::vec4(p_r * cos(i * phi * PI / 180.0), p_r * sin(i * phi * PI / 180.0), 0, 1));
    }
    for (int i = 0; i < p_n; i++)
    {
        points.append(glm::vec4(p_r * cos(i * phi * PI / 180.0), p_r * sin(i * phi * PI / 180.0), p_h, 1));
    }
}
int Prism::get_n()
{
    return p_n;
}
float Prism::get_ex()
{
    return p_ex;
}
float Prism::get_ey()
{
    return p_ey;
}
float Prism::get_ez()
{
    return p_ez;
}
float Prism::get_d()
{
    return p_d;
}
int Prism::get_size()
{
    return points.size();
}
float Prism::point_at_x(int i)
{
    return points.at(i).x;
}
float Prism::point_at_y(int i)
{
    return points.at(i).y;
}
float Prism::point_at_z(int i)
{
    return points.at(i).z;
}

void Prism::transform_vertex(glm::mat4x4 matrix1, glm::mat4x4 matrix2, glm::mat4x4 matrix3, int number)
{
    points[number] = points.at(number) * matrix1 * matrix2 * matrix3;
}
void Prism::transform_vertex(glm::mat4x4 matrix1, glm::mat4x4 matrix2, glm::mat4x4 matrix3, glm::mat4x4 matrix4, int number)
{
    points[number] = points.at(number) * matrix1 * matrix2 * matrix3 * matrix4;
}
void Prism::transform_vertex(float d, int number)
{
    points[number].x = d * points.at(number).x / points.at(number).z;
    points[number].y = d * points.at(number).y / points.at(number).z;
}
void Prism::update_prism()
{
    points.clear();
    init_points();
}
void Prism::on_n_changed(int new_n)
{
    p_n = new_n;
    update_prism();
    emit prism_updated();
}
void Prism::on_r_changed(int new_r)
{
    p_r = new_r / 100.0;
    update_prism();
    emit prism_updated();
}
void Prism::on_h_changed(int new_h)
{
    p_h = new_h / 100.0;
    update_prism();
    emit prism_updated();
}
void Prism::on_ex_changed(int new_ex)
{
    p_ex = new_ex / -100.0;
    update_prism();
    emit prism_updated();
}
void Prism::on_ey_changed(int new_ey)
{
    p_ey = new_ey / -100.0;
    update_prism();
    emit prism_updated();
}
void Prism::on_ez_changed(int new_ez)
{
    p_ez = new_ez / -100.0;
    update_prism();
    emit prism_updated();
}
void Prism::on_d_changed(int new_d)
{
    p_d = new_d / 100.0;
    update_prism();
    emit prism_updated();
}
