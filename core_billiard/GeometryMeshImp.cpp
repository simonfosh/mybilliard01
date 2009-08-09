#include "my_render_imp.h"
namespace my_render_imp {


void GeometryMeshImp::draw( Render * render ) {
    MY_FOR_EACH( Primitives, primitive, primitives_ ) {
        (*primitive)->draw( render );
    }
}

size_t GeometryMeshImp::getNumVertex() {
    return positions_.size();
}

void GeometryMeshImp::setPositions( const vector< NxReal > & stream ) {
    //TODO
}

void GeometryMeshImp::setNormals( const vector< NxReal > & stream ) {
    //TODO
}

void GeometryMeshImp::setTexCoords( const vector< NxReal > & stream ) {
    //TODO
}

void GeometryMeshImp::appendPrimitive( GeometryMeshPrimitiveImp * primitive ) {
    primitives_.push_back( primitive );
}

size_t GeometryMeshImp::getNumPrimitives() {
    return primitives_.size();
}

GeometryMeshPrimitiveImp * GeometryMeshImp::getPrimitive( size_t index ) {
    return primitives_.at( index );
}


} // namespace
