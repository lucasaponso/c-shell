pkgname=cshell
pkgver=1.0.0
pkgrel=1
pkgdesc="A custom shell written in C using CMake"
arch=('x86_64')
url="https://example.com/my-shell"
license=('GPL3')
depends=('glibc')
makedepends=('cmake' 'gcc' 'make')
source=()
sha256sums=()

build() {
  cd "$startdir"
  mkdir -p build
  cd build
  cmake ..
  make
}

package() {
  cd "$startdir"
  install -Dm755 bin/cshell "$pkgdir/usr/bin/cshell"
}
