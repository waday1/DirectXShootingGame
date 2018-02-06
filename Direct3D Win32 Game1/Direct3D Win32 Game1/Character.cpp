#include "pch.h"
#include "Character.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Character::Character()
{
}

Character::Character(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,float speed,float scale, const wchar_t * filename, bool isAlive)
{
	/*Microsoft::WRL::ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		DirectX::CreateWICTextureFromFile(Device.Get(), filename,
			resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	Microsoft::WRL::ComPtr<ID3D11Texture2D> cat;
	DX::ThrowIfFailed(resource.As(&cat));

	CD3D11_TEXTURE2D_DESC catDesc;
	cat->GetDesc(&catDesc);

	position = pos;*/


}

Character::~Character()
{
}

void Character::Update(DX::StepTimer const& timer)
{
}

void Character::Render(DirectX::SpriteBatch* spriteBatch)
{

	//m_spriteBatch->Draw(texture.Get(), position, nullptr, Colors::White, 0.f,Vector2::Zero);
}

void Character::MoveUpdate(Vector2 vec)
{
	position += vec;
}
