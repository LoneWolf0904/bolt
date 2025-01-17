#include "Transform.h"

namespace bolt
{
	rend::mat4 Transform::model()
	{
		rend::mat4 rtn(1.0f);

		// TODO: Translation
		rtn = rend::translate(rtn, m_position);

		// TODO: Rotation
		rtn = rend::rotate_xyz(rtn, m_rotation);

		// TODO: Size
		rtn = rend::scale(rtn, m_scale);
		return rtn;
	}
}
