#if !defined(INTERSECTION_DATA_HPP)
#define INTERSECTION_DATA_HPP

#include <iostream>

// #include "./vectors/vectors.cpp"
// using namespace vectors;

class IntersectionData {
    private:
        bool isIntersecting;
        float IntersectionDepth;

        // Vector3 iPoint_1, iPoint_2;
        
    public:
        IntersectionData(bool _isI, float _iDepth) : isIntersecting{_isI}, IntersectionDepth{_iDepth} {}
        IntersectionData(float _iDepth) : isIntersecting{true}, IntersectionDepth(_iDepth) {}

        bool getIntersectionState() const { return isIntersecting; }
        float getIntersectionDepth() const { return IntersectionDepth; }

        friend std::ostream& operator << (std::ostream&, IntersectionData&);
};

std::ostream& operator << (std::ostream& dout, IntersectionData& iData) {
    dout << "<IntersectionData> State: " << iData.getIntersectionState() << " | " 
         << "Distance: " << iData.getIntersectionDepth();
}

#endif // INTERSECTION_DATA_HPP
