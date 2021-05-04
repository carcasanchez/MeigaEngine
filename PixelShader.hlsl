cbuffer CBuf
{
	float4 face_colors[6];
};

float4 main(uint trangleID : SV_PrimitiveID) : SV_Target
{
	return face_colors[(trangleID / 2) % 6];
}