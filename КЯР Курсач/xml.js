$(document).ready(function() {
    // Получение параметра из URL
    const urlParams = new URLSearchParams(window.location.search);
    const articul = urlParams.get('articul');

    // Загрузка XML-файла
    $.ajax({
      type: "GET",
      url: "sample.xml",
      dataType: "xml",
      success: function(xml) {
        $(xml).find('car').each(function() {
          if ($(this).find('articul').text() === articul) {
            var imgSrc = $(this).find('img').text();
            var name = $(this).find('name').text();
            var price = $(this).find('price').text();
            var motor = $(this).find('motor').text();
            var color = $(this).find('color').text();
            var about_car = $(this).find('about_car').text();

            // Заполнение информации о книге на странице
            $('#productImage').attr('src', imgSrc);
            $('#sample-h3').text(name);
            $('#a-price').text(price);
            $('#a-motor').text(motor);
            $('#a-color').text(color);
            $('#a-about').text(about_car);
          }
        });
      }
    });
  });


