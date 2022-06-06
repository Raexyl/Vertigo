#ifndef MATERIAL_H
#define MATERIAL_H

namespace Impact
{
	class Material
	{
		public:
			Material();
			Material(float Restitution, float StaticMu, float DynamicMu);
			~Material();

		public:
			float restitution;
			float staticMu;
			float dynamicMu;
	};
}

#endif