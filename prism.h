#ifndef PRISM_H
#define PRISM_H

#define PI 3.14159265
#include "include/glm/mat4x4.hpp"
#include "include/glm/vec4.hpp"
#include <QVector>
#include <QObject>

class Prism : public QObject
{
    Q_OBJECT
private:
    int p_n;
    float p_r, p_h, p_ex, p_ey, p_ez, p_d;
    QVector<glm::vec4> points;
    void update_prism();
public:
    Prism();
    Prism(int n, float r, float h, float ex, float ey, float ez, float d);
    ~Prism(){};
    int get_n();
    float get_ex();
    float get_ey();
    float get_ez();
    float get_d();
    int get_size();
    float point_at_x(int);
    float point_at_y(int);
    float point_at_z(int);
    void init_points();
    void transform_vertex(glm::mat4x4 matrix1, glm::mat4x4 matrix2, glm::mat4x4 matrix3, int number);
    void transform_vertex(glm::mat4x4 matrix1, glm::mat4x4 matrix2, glm::mat4x4 matrix3, glm::mat4x4 matrix4, int number);
    void transform_vertex(float d, int number);

signals:
    void prism_updated();
public slots:
    void on_n_changed(int new_n);
    void on_r_changed(int new_r);
    void on_h_changed(int new_h);
    void on_ex_changed(int new_ex);
    void on_ey_changed(int new_ey);
    void on_ez_changed(int new_ez);
    void on_d_changed(int new_d);

};

#endif // PRISM_H
