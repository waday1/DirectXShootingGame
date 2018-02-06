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
	delete texture;
}

void Character::Update(DX::StepTimer const& timer, ShotManager* shotmanager)
{
}

void Character::Render(DirectX::SpriteBatch* spriteBatch)
{
	spriteBatch->Draw(texture->texture.Get(), GetPosition(), nullptr, Colors::White, 0.0f,texture->GetOrigin(), GetScale());
}

void Character::MoveUpdate(Vector2 vec)
{
	position += vec;
}
