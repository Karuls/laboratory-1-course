
$(document).ready(function() {
    // Получение параметра из URL
    const urlParams = new URLSearchParams(window.location.search);
    const articul = urlParams.get('articul');

    // Загрузка XML-файла
    $.ajax({
        type: "GET",
        url: "Auto_park.xml",
        dataType: "xml",
        success: function(xml) {
            $(xml).find('info_about_car_example').each(function() {
                if ($(this).find('articul').text() === articul) {
                    var motorV = $(this).find('a-motor-V').text();
                    var motorHP = $(this).find('a-motor-HP').text();
                    var fuel = $(this).find('Toplivo').text();
                    var year = $(this).find('data-year').text();
                    var cost = $(this).find('cost').text();

                    // Заполнение информации о машине на странице
                    $('#a-motor-V').text(motorV);
                    $('#a-motor-HP').text(motorHP);
                    $('#Toplivo').text(fuel);
                    $('#data-year').text(year);
                    $('#cost').text(cost);
                    
                    // Добавление других деталей, если есть, например изображение и название
                    // $('#carImage').attr('src', 'path_to_image_based_on_articul_or_other_data');
                    // $('#carName').text('Car Model Name Based on Articul or other data');
                }
            });
        }
    });
});
