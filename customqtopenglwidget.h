#ifndef CUSTOMQTOPENGLWIDGET_H
#define CUSTOMQTOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <cmath>
#include <iostream>

#include "prism.h"
#include "include/glm/mat4x4.hpp"
#include "include/glm/vec4.hpp"


#define PI 3.14159265

class customqtopenglwidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    customqtopenglwidget(QWidget* parent = nullptr)
    {
        Q_UNUSED(parent);
    }
    Prism prism1 = Prism(3, 0.2, 0.4, 0.000000001, 0.000000001, 1.0, 0.0);
    Prism prism2 = Prism(3, 0.2, 0.4, 0.2, 0.4, 0.6, 0.3);
public slots:
    void repaint_par();
    void repaint_per();
protected:
    void initializeGL() override
    {
        if(this->objectName() == "mainOpenGLWidget")
        {
            glClearColor(1,1,1,1);
            this->set_view();
        }
        else
        {
            glClearColor(1,1,1,1);
            this->perspective();
        }
    }
    void paintGL() override
    {
        if(this->objectName() == "mainOpenGLWidget")
        {
            int n = prism1.get_n();
            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);
            for (int i = 0; i < n - 1; i++)
            {
                glVertex2f(prism1.point_at_x(i), prism1.point_at_y(i));
                glVertex2f(prism1.point_at_x(i + 1), prism1.point_at_y(i + 1));
            }
            glVertex2f(prism1.point_at_x(n - 1), prism1.point_at_y(n - 1));
            glVertex2f(prism1.point_at_x(0), prism1.point_at_y(0));
            for (int i = n; i < 2 * n - 1; i++)
            {
                glVertex2f(prism1.point_at_x(i), prism1.point_at_y(i));
                glVertex2f(prism1.point_at_x(i + 1), prism1.point_at_y(i + 1));
            }
            glVertex2f(prism1.point_at_x(2 * n - 1), prism1.point_at_y(2 * n - 1));
            glVertex2f(prism1.point_at_x(n), prism1.point_at_y(n));
            for (int i = 0; i < n; i++)
            {
                glVertex2f(prism1.point_at_x(i), prism1.point_at_y(i));
                glVertex2f(prism1.point_at_x(i + n), prism1.point_at_y(i + n));
            }
            glEnd();
        }
        else
        {
            int n = prism2.get_n();
            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);
            for (int i = 0; i < n - 1; i++)
            {
                glVertex2f(prism2.point_at_x(i), prism2.point_at_y(i));
                glVertex2f(prism2.point_at_x(i + 1),prism2.point_at_y(i + 1));
            }
            glVertex2f(prism2.point_at_x(n - 1), prism2.point_at_y(n - 1));
            glVertex2f(prism2.point_at_x(0), prism2.point_at_y(0));
            for (int i = n; i < 2 * n - 1; i++)
            {
                glVertex2f(prism2.point_at_x(i), prism2.point_at_y(i));
                glVertex2f(prism2.point_at_x(i + 1), prism2.point_at_y(i + 1));
            }
            glVertex2f(prism2.point_at_x(2 * n - 1), prism2.point_at_y(2 * n - 1));
            glVertex2f(prism2.point_at_x(n), prism2.point_at_y(n));
            for (int i = 0; i < n; i++)
            {
                glVertex2f(prism2.point_at_x(i), prism2.point_at_y(i));
                glVertex2f(prism2.point_at_x(i + n), prism2.point_at_y(i + n));
            }
            glEnd();
        }

    }

private:
    glm::mat4x4 turn_phi_z;
    glm::mat4x4 turn_90_phi_y;
    glm::mat4x4 move;
    glm::mat4x4 switch_axis;
    glm::mat4x4 init_turn_phi_z(float phi);
    glm::mat4x4 init_turn_phi_z_val(float cosine, float sine);
    glm::mat4x4 init_turn_90_phi_y(float phi);
    glm::mat4x4 init_turn_90_phi_y_val(float cosine, float sine);
    glm::mat4x4 init_move(float x, float y, float z);
    glm::mat4x4 init_switch_axis();
    void set_view();
    void perspective();
};

#endif // CUSTOMQTOPENGLWIDGET_H
