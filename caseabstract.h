#ifndef CASEABSTRACT_H
#define CASEABSTRACT_H



class CaseAbstract
{
public:
    virtual void rysuj() const = 0;
    virtual void check_hover(const float &pos_x, const float &pos_y) = 0;
    virtual void hover_reaction() = 0;
    virtual void randomize_position(float &pos_x, float &pos_y, const float &bounding_width, const float &bounding_height, const bool &overlapping) = 0;
};

#endif // CASEABSTRACT_H
