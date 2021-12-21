#if !defined(BOX_COLLIDOR_HPP)
#define BOX_COLLIDOR_HPP

#include "collidorBase.hpp"
#include <iterator>

using namespace vectors;

class BoxCollidor : public Collidor {
    public:
        Vector3 Dimension;

        Vector3 minExtent;
        Vector3 maxExtent;

        BoxCollidor(Vector3 _position, Vector3 _dimension) : Dimension{_dimension} {
            Position = _position;

            Vector3 tempDim = Dimension;
            tempDim.scale(0.5);

            minExtent = _position - tempDim;
            maxExtent = _position + tempDim;

            CollidorType = Collidor::BoxCollidor_T;
            isTrigger = false;
        }

        BoxCollidor(Vector3 _position, Vector3 _dimension, bool _isTrigger) : Dimension{_dimension} {
            Position = _position;

            Vector3 tempDim = Dimension;
            tempDim.scale(0.5);

            minExtent = _position - tempDim;
            maxExtent = _position + tempDim;

            CollidorType = Collidor::BoxCollidor_T;
            isTrigger = _isTrigger;
        }

        BoxCollidor(BoxCollidor& other) : Dimension{other.Dimension} {
            Position = other.Position;

            Vector3 tempDim = other.Dimension;
            tempDim.scale(0.5);

            minExtent = other.Position - tempDim;
            maxExtent = other.Position + tempDim;

            CollidorType = Collidor::BoxCollidor_T;
            isTrigger = other.isTrigger;
        }

        virtual IntersectionData Collide(Collidor*) override;
        virtual std::vector<IntersectionData> Collide(std::vector<Collidor*>&) override;
        friend std::ostream& operator << (std::ostream&, BoxCollidor&);
};

std::ostream& operator << (std::ostream& dout, BoxCollidor& collidor) {
    dout << "<SphereCollidor>" << std::endl
         << "Position   : " << collidor.Position << std::endl

        //  << "Dimensions : " << collidor.Dimension << std::endl << std::endl
        //  << "Extents:-" << std::endl
        //  << "Min        : " << collidor.minExtent << std::endl
        //  << "Max        : " << collidor.maxExtent;

         << "Dimensions : " << collidor.Dimension << std::endl
         << "Min extent : " << collidor.minExtent << std::endl
         << "Max extent : " << collidor.maxExtent;

    return dout;
}

#endif // BOX_COLLIDOR_HPP
