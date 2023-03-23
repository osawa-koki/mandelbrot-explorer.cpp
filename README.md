# mandelbrot-explorer.cpp

🌀🌀🌀 C++でマンデルブロ集合を描写してみた！  

## 実行方法

DevContainerに入ってから、以下のコマンドを実行してください。  
C++の開発環境とffmpegの実行環境が必要です。  

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
| default-width | 画像の幅 |
| default-height | 画像の高さ |
