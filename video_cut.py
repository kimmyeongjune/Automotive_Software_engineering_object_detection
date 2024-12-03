from moviepy.editor import VideoFileClip

# 원본 비디오 파일 경로
input_video = "car/output.avi"

# 출력 파일 경로
output_video = "car/cropped_output.avi"

# 비디오 로드
video = VideoFileClip(input_video)

# 자를 시작 시간 (0초에서 시작)
start_time = 0  # 시작 시간
end_time = 4    # 끝 시간 (4초)

# 비디오 자르기
cut_video = video.subclip(start_time, end_time)

# 자른 비디오 저장
cut_video.write_videofile(output_video, codec="png")  # AVI 형식으로 저장
