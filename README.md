# mandelbrot-explorer.cpp

🌀🌀🌀 C++でマンデルブロ集合を描写してみた！  
複数の画像を結合して動画を作成することもできます。  

![成果物](./docs/img/fruit.gif)  

## 実行方法

DevContainerに入ってから、以下のコマンドを実行してください。  
C++の開発環境とffmpegの実行環境があれば、実行できます。  

```shell
make
make run ARGS="コマンドライン引数"
```

---

また、画像ファイルから動画を作成する場合は、以下のコマンドを実行してください。  

```shell
ffmpeg -r 30 -i ./work/★name★/%08d.png -vcodec libx264 -pix_fmt yuv420p -r 60 ./dist/video.mp4
```

---

サンプルとして`./run.sh`を用意しています。  

Windowsユーザの場合は`dos2unix ./run.sh`を実行してください。  
これは、`./run.sh`の改行コードを`LF`に変換するためです。  

### コマンドライン引数

| キー | 説明 |
| --- | --- |
| name | 画像の名前 |
| from | 画像の開始位置 |
| upto | 画像の終了位置 |
| aspect-ratio | 画像のアスペクト比 |
| shrink-ratio | 画像の縮小率 |
| filesize-height | 画像の高さ |
| start-x | 画像の開始位置のX座標 |
| start-y | 画像の開始位置のY座標 |
| default-width | 虚数平面の幅 |
| default-height | 虚数平面の高さ |

- `from`と`upto`は、`from`から`upto`までの間で、`upto`を含む範囲で画像を生成します。
- 動画を作成する際には、`from`には`0`を指定してください。
- `filesize-height`は、画像の高さを指定します。  
- 画像の幅は、`aspect-ratio`と`filesize-height`から計算されます。
- `filesize-height`の値が大きいと、処理に時間がかかります。

## CI/CD

GitHub Actionsを用いて、CI/CDを実現しています。  
`main`ブランチにpushすると、ビルド・実行とデプロイが行われます。  
