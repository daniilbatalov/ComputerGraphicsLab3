#include <customqtopenglwidget.h>
#include <cmath>


glm::mat4x4 customqtopenglwidget::init_turn_phi_z(float phi)
{
    return glm::mat4x4(cos(phi * PI / 180.0), sin(phi * PI / 180.0), 0, 0,
                       -1 * sin(phi * PI / 180.0), cos(phi * PI / 180.0), 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1);
}
glm::mat4x4 customqtopenglwidget::init_turn_phi_z_val(float cosine, float sine)
{
    return glm::mat4x4(cosine, sine, 0, 0,
                       -1 * sine, cosine, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1);
}
glm::mat4x4 customqtopenglwidget::init_turn_90_phi_y(float phi)
{
    return glm::mat4x4(sin(phi * PI / 180.0), 0, -1 * cos(phi * PI / 180.0), 0,
                       0, 1, 0, 0,
                       cos(phi * PI / 180.0), 0, sin(phi * PI / 180.0), 0,
                       0, 0, 0, 1);
}
glm::mat4x4 customqtopenglwidget::init_turn_90_phi_y_val(float cosine, float sine)
{
    return glm::mat4x4(sine, 0, -1 * cosine, 0,
                       0, 1, 0, 0,
                       cosine, 0, sine, 0,
                       0, 0, 0, 1);
}
glm::mat4x4 customqtopenglwidget::init_move(float x, float y, float z)
{
    return glm::mat4x4(1, 0, 0, x,
                       0, 1, 0, y,
                       0, 0, 1, z,
                       0, 0, 0, 1);
}
glm::mat4x4 customqtopenglwidget::init_switch_axis()
{
    return glm::mat4x4(0, 1, 0, 0,
                       0, 0, 1, 0,
                      -1, 0, 0, 0,
                       0, 0, 0, 1);
}
void customqtopenglwidget::set_view()
{
    float ex, ey, ez, modv, mode;
    ex = prism1.get_ex();
    ey = prism1.get_ey();
    ez = prism1.get_ez();
    modv = sqrt(ex * ex + ey * ey);
    mode = sqrt(ex * ex + ey * ey + ez * ez);
    turn_phi_z = init_turn_phi_z_val((ex / modv), (ey / modv));
    turn_90_phi_y = init_turn_90_phi_y_val((ez / mode), (modv / mode));
    move = init_move(-1 * mode, 0, 0);
    switch_axis = init_switch_axis();
    for(int i = 0; i < prism1.get_size(); i++)
    {
        prism1.transform_vertex(turn_phi_z, turn_90_phi_y, move, switch_axis, i);
    }
}
void customqtopenglwidget::perspective()
{
    float ex, ey, ez, modv, mode, d;
    ex = prism2.get_ex();
    ey = prism2.get_ey();
    ez = prism2.get_ez();
    d = prism2.get_d();
    modv = sqrt(ex * ex + ey * ey);
    mode = sqrt(ex * ex + ey * ey + ez * ez);
    turn_phi_z = init_turn_phi_z_val((ex / modv), (ey / modv));
    turn_90_phi_y = init_turn_90_phi_y_val((ez / mode), (modv / mode));
    move = init_move(-1 * mode, 0, 0);
    switch_axis = init_switch_axis();
    for(int i = 0; i < prism2.get_size(); i++)
    {
        prism2.transform_vertex(turn_phi_z, turn_90_phi_y, move, switch_axis, i);
        prism2.transform_vertex(d, i);
    }
}
void customqtopenglwidget::repaint_par()
{
    set_view();
    update();
}
void customqtopenglwidget::repaint_per()
{
    perspective();
    update();
}
