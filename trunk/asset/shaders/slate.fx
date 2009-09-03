//**************************************************************//
//  Effect File exported by RenderMonkey 1.6
//
//  - Although many improvements were made to RenderMonkey FX  
//    file export, there are still situations that may cause   
//    compilation problems once the file is exported, such as  
//    occasional naming conflicts for methods, since FX format 
//    does not support any notions of name spaces. You need to 
//    try to create workspaces in such a way as to minimize    
//    potential naming conflicts on export.                    
//    
//  - Note that to minimize resulting name collisions in the FX 
//    file, RenderMonkey will mangle names for passes, shaders  
//    and function names as necessary to reduce name conflicts. 
//**************************************************************//

//--------------------------------------------------------------//
// slate
//--------------------------------------------------------------//
//--------------------------------------------------------------//
// Pass 0
//--------------------------------------------------------------//
string slate_Pass_0_Model : ModelData = "..\\..\\..\\..\\..\\..\\..\\..\\Program Files\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Sphere.3ds";

shared float4 fvEyePosition : ViewPosition;
shared float4x4 matView : View;
float4x4 matWorldViewProjection : WorldViewProjection;
float4x4 matWorldView : WorldView;
float4x4 matWorld : World;

shared float4 Light0_Position
<
   string UIName = "Light0_Position";
   string UIWidget = "Direction";
   bool UIVisible =  true;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 0.00, 0.00, -400.00, 1.00 );
float4x4 Light0_WorldLightProjection
<
   string UIName = "Light0_WorldLightProjection";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
> = float4x4( 1.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00, 0.00, 0.00, 0.00, 1.00 );

struct VS_INPUT 
{
   float4 Position : POSITION0;
   float2 Texcoord : TEXCOORD0;
   float3 Normal :   NORMAL0;
   
};

struct VS_OUTPUT 
{
   float4 Position :           POSITION0;
   float2 Texcoord :           TEXCOORD0;
   float3 ViewDirection :      TEXCOORD1;
   float3 LightDirection :     TEXCOORD2;
   float3 Normal :             TEXCOORD3;
   float3 PositionFromLight0 : TEXCOORD4;   
};

VS_OUTPUT slate_Pass_0_Vertex_Shader_vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output;

   Output.Position         = mul( Input.Position, matWorldViewProjection );
   Output.Texcoord         = Input.Texcoord;

   float3 fvWorld          = mul( Input.Position, matWorld );

   float3 fvEminusW        = fvEyePosition - fvWorld;
   Output.ViewDirection    = mul( fvEminusW, matView );

   float3 fvLminusW        = Light0_Position - fvWorld;   
   Output.LightDirection   = mul( fvLminusW, matView );

   float3 fvNormal         = Input.Normal;
   Output.Normal           = mul( fvNormal, matWorldView );
   
   float4 posFromLight0    = mul( Input.Position, Light0_WorldLightProjection );

   Output.PositionFromLight0.x = ( posFromLight0.x / posFromLight0.w + 1 ) * 0.5f;
   Output.PositionFromLight0.y = (-posFromLight0.y / posFromLight0.w + 1 ) * 0.5f;
   Output.PositionFromLight0.z = posFromLight0.z / posFromLight0.w;
   
   return( Output );
   
}



float4 fvAmbient
<
   string UIName = "fvAmbient";
   string UIWidget = "Color";
   bool UIVisible =  true;
> = float4( 0.17, 0.17, 0.17, 1.00 );
float4 fvSpecular
<
   string UIName = "fvSpecular";
   string UIWidget = "Color";
   bool UIVisible =  true;
> = float4( 0.16, 0.16, 0.16, 1.00 );
float4 fvDiffuse
<
   string UIName = "fvDiffuse";
   string UIWidget = "Color";
   bool UIVisible =  true;
> = float4( 0.89, 0.88, 0.85, 1.00 );
float fSpecularPower
<
   string UIName = "fSpecularPower";
   string UIWidget = "Numeric";
   bool UIVisible =  true;
   float UIMin = 1.00;
   float UIMax = 100.00;
> = float( 2.00 );
float depthBias
<
   string UIName = "depthBias";
   string UIWidget = "Numeric";
   bool UIVisible =  true;
   float UIMin = -1.00;
   float UIMax = 1.00;
> = float( 0.01 );
texture base_Tex
<
   string ResourceName = "..\\textures\\green.jpg";
>;
sampler2D baseMap = sampler_state
{
   Texture = (base_Tex);
   ADDRESSU = WRAP;
   ADDRESSV = WRAP;
   MINFILTER = LINEAR;
   MAGFILTER = LINEAR;
   MIPFILTER = LINEAR;
};
texture shadow0_Tex
<
   string ResourceName = "..\\textures\\shadow_map_captured.png";
>;
sampler2D shadowMap0 = sampler_state
{
   Texture = (shadow0_Tex);
   MINFILTER = LINEAR;
   MIPFILTER = LINEAR;
   MAGFILTER = LINEAR;
};

struct PS_INPUT 
{
   float2 Texcoord :           TEXCOORD0;
   float3 ViewDirection :      TEXCOORD1;
   float3 LightDirection:      TEXCOORD2;
   float3 Normal :             TEXCOORD3;
   float3 PositionFromLight0 : TEXCOORD4;   
};

float4 slate_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR0
{
   const float3 lightDirection   = normalize( Input.LightDirection );
   const float3 normal           = normalize( Input.Normal );
   const float  N_Dot_L          = dot( normal, lightDirection ); 
   const float  diffuseAttn      = clamp( N_Dot_L, 0.f, 1.f );

   const float3 reflection       = normalize( ( ( 2.f * normal ) * ( N_Dot_L ) ) - lightDirection ); 
   const float3 viewDirection    = normalize( Input.ViewDirection );
   const float  R_Dot_V          = dot( reflection, viewDirection );
   const float  specularAttn     = pow( clamp( R_Dot_V, 0.00001f, 1.f ), fSpecularPower );

   const float4 fvBaseColor      = tex2D( baseMap, Input.Texcoord );

   const float4 colorOnShadowMap0 = tex2D( shadowMap0, Input.PositionFromLight0.xy );
   const float  depthOnShadowMap0 = colorOnShadowMap0.r + colorOnShadowMap0.g / 127.f
                                  + colorOnShadowMap0.b / ( 127.f * 127.f )
                                  + depthBias;
   const float  actualDepth       = Input.PositionFromLight0.z;

   const float4 colorOutShadow    = ( fvAmbient + diffuseAttn * fvDiffuse ) * fvBaseColor
                                  + specularAttn * fvSpecular;
   const float4 colorUnderShadow  = fvAmbient * fvBaseColor;

//   return colorOnShadowMap0;
//   return depthOnShadowMap0;
//   return actualDepth;
//   return colorUnderShadow;
//   return color;

   const float4 actualColor1 = ceil( actualDepth - depthOnShadowMap0 ) * colorUnderShadow;
   const float4 actualColor2 = ceil( depthOnShadowMap0 - actualDepth ) * colorOutShadow;
   return actualColor1 + actualColor2;
}



//--------------------------------------------------------------//
// Technique Section for slate
//--------------------------------------------------------------//
technique slate
{
   pass Pass_0
   {
      VertexShader = compile vs_1_1 slate_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 slate_Pass_0_Pixel_Shader_ps_main();
   }

}

