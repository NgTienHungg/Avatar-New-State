# Avatar new state

## 1. Tổng quan

- Sản phẩm của cuộc thi làm game C++ từ CLB ProPTIT.

- Thể loại: game kim cương, chiến thắng để mở khóa các màn mới, có xếp hạng.

- Sử dụng: `C++` + `SFML`.

- [Docs about game](https://docs.google.com/document/d/1H6pM1pklrO6mXRImTtUcyvhNaCIqRWvC/edit?usp=sharing&ouid=102851195346342573678&rtpof=true&sd=true)

- [Video demo](https://www.facebook.com/100063577121993/videos/1031340504115976/)

## 2. Nhận xét

- Hoàn thành:

  ![menu](https://user-images.githubusercontent.com/80816285/157796799-93c082b3-df33-40a3-b07d-adb5c84ae3ec.png)

  - GUI, parallax background, asset, music và sound.
  - Các state game: intro, menu, setting, profile, help, rank, select map, select character, play, end, pause, quit.

  - Manager:

    - Quản lý thông tin người dùng

    - Load dữ liệu người dùng cũ khi mới vào game (đọc ghi file cơ bản)

    - Profile có link đường dẫn tới FB và github

  - Gameplay:

    ![play](https://user-images.githubusercontent.com/80816285/157796964-fd5529b3-d882-4e56-932d-2abd63661d65.png)

    - Effect intro, thông báo, xóa các item khi đã ăn...

    - Trạng thái và thuộc tính của nhân vật, quái

    - Xử lý thời gian, logic lượt chơi

    - Bàn kim cương: select, swap, match, moving, random item...

    - Bot tự tìm nước tối ưu để ăn

    - Reset game khi không còn nước nào để ăn

    - Xử lý thắng thua

- Chưa làm được:

  - Shadow effect: hiệu ứng đen dần để chuyển giữa các state game.

  - Chưa thể làm nhiều map do hạn chế asset.

  - Chưa đưa được skill vào game.

## 3. Công cụ hỗ trợ

- Khóa học: [Hướng dẫn làm game Jack Adventure](https://www.youtube.com/watch?v=ANjk6LsShRo&list=PLZd7ojlRK0bwrL8060OGurG_kaeJc_QOH)

- Aseprite: chỉnh sửa ảnh pixel, tạo spritesheet.

- Audacity: chỉnh sửa âm thanh

- [https://ezgif.com/sprite-cutter](https://ezgif.com/sprite-cutter): cắt spritesheet ra thành các frame nhỏ.

- [https://loader.to/vi79/youtube-wav-converter.html](https://loader.to/vi79/youtube-wav-converter.html): dùng để tải nhạc từ youtube

- Free game 2D assets:

  - [https://craftpix.net/freebies/](https://craftpix.net/freebies/)

  - [https://itch.io/game-assets/free](https://itch.io/game-assets/free)

- Free sound:

  - [https://mixkit.co/free-sound-effects/game/](https://mixkit.co/free-sound-effects/game/)

  - [https://pixabay.com/sound-effects/search/game/](https://pixabay.com/sound-effects/search/game/)

  - [https://www.zapsplat.com/sound-effect-category/game-sounds/](https://www.zapsplat.com/sound-effect-category/game-sounds/)
