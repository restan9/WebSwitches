SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

-- --------------------------------------------------------

--
-- Структура таблицы `Switches`
--

CREATE TABLE `Switches` (
  `id` int(6) UNSIGNED NOT NULL,
  `Led_Number` varchar(20) NOT NULL,
  `Led_State` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `Switches`
--

INSERT INTO `Switches` (`id`, `Led_Number`, `Led_State`) VALUES
(1, 'LED_1', 'OFF'),
(2, 'LED_2', 'OFF'),
(3, 'LED_3', 'OFF'),
(4, 'LED_4', 'OFF'),
(5, 'LED_5', 'OFF'),
(6, 'LED_6', 'OFF');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `Switches`
--
ALTER TABLE `Switches`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `Switches`
--
ALTER TABLE `Switches`
  MODIFY `id` int(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=34;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
