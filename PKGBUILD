# Maintainer: Aponso <your@email.com>
pkgname=c-shell
pkgver=1.0
pkgrel=1
pkgdesc="A custom Unix shell written in C"
arch=('x86_64')
url="https://example.com"
license=('MIT')
depends=()
makedepends=('cmake' 'gcc' 'make')
source=("$pkgname-$pkgver.tar.gz")
md5sums=('SKIP')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  ./build.sh
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  ./build.sh "$pkgdir"
  install -Dm755 build/myshell "$pkgdir/usr/bin/myshell"
}

