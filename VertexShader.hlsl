struct VSout
{
	float3 color : Color; 
	float4 pos : SV_Position;
};

VSout main(float2 pos : Position, float3 color : Color)
{
	VSout outStructure;
	outStructure.pos = float4(pos.x, pos.y, 0.0f, 1.0f);
	outStructure.color = color;
	return outStructure;
}